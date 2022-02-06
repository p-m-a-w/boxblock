#include <thread>
#include <cstdlib>
#include <csignal>
#include <unistd.h>
#include "ui.hpp"
#include "chain.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"

int main() {
    float brightness_step = 10.0 / 1618.0, splash_brigtness = 1.0f + brightness_step;
    int selected_scene = 1, vote = 0;
    auto screen = ScreenInteractive::FixedSize(_WIDTH / 1.9, _HEIGHT / 4);
    vector<std::string> candidates = {
        "No vote",
        "Khun A",
        "Khun B",
        "Khun C",
        "Khun D",
    };
    static vector<block> chain = {};
    chain.reserve(10000);

    SceneConfiguration config = {
        .screen = &screen,
        .selected_scene = &selected_scene,
        .vote = &vote,
    };

    if (!starterDataCheck(FILENAME)) createChainFile(FILENAME, chain); 
    importChain(FILENAME, chain, false); 

    auto current_scene = Container::Tab({
        Scene::splash(splash_brigtness),
        Scene::vote(config, candidates, chain),
        Scene::error(config, chain),
        Scene::summary(config, candidates, chain),
    }, &selected_scene);

    auto component = Renderer(current_scene, [&] {
        if (selected_scene == 0) {
            raise(SIGWINCH);
            usleep(10 * 1000); // 10ms
            if (splash_brigtness > 0.0) splash_brigtness -= brightness_step;
            else selected_scene++;
        } else if (selected_scene == 1) {
            if (!hashCheck(chain)) selected_scene = 2;
        } else if (selected_scene == 3) {
            raise(SIGWINCH);
        }

        return hbox({
            current_scene->Render(),
        }) | border;
    });

    screen.Loop(component);
    return 0;
}
