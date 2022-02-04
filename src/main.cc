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
    int selected_scene = 0, vote = 0;
    auto screen = ScreenInteractive::FixedSize(WIDTH / 1.9, HEIGHT / 4);
    vector<std::string> candidates = {
        "No vote",
        "Khun A",
        "Khun B",
        "Khun C",
        "Khun D",
    };
    vector<block> chain = {};

    SceneConfiguration config = {
        .screen = &screen,
        .selected_scene = &selected_scene,
        .vote = &vote,
    };
    auto current_scene = Container::Tab({
        Scene::splash(splash_brigtness),
        Scene::vote(config, candidates, chain),
        Scene::error(config),
        // Scene::summary(config, candidates, chain),
    }, &selected_scene);
    auto component = Renderer(current_scene, [&] {
        if (selected_scene == 0) {
            raise(SIGWINCH);
            usleep(10 * 1000); // 1ms
            if (splash_brigtness > 0.0) splash_brigtness -= brightness_step;
            else selected_scene++;
        } else if (selected_scene == 1) {
            if (!starterDataCheck(FILENAME)) createChainFile(FILENAME, chain);
            importChain(FILENAME, chain);
            if (!hashCheck(chain)) selected_scene = 2;
        }

        return hbox({
            current_scene->Render(),
        }) | border;
    });

    screen.Loop(component);
    return 0;
}
