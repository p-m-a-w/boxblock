#include <thread>
#include <cstdlib>
#include <csignal>
#include <unistd.h>
#include "ui.hpp"
#include "ftxui/component/screen_interactive.hpp"
#include "ftxui/component/component.hpp"

int main(int argc, const char* argv[]) {
    float brightness_step = 10.0 / 1618.0, splash_brigtness = 1.0f + brightness_step;
    int selected_scene = 2, choice = 0;
    auto screen = ScreenInteractive::FixedSize(WIDTH / 1.9, HEIGHT / 4);
    std::vector<std::string> candidates = {
        "No vote",
        "Khun A",
        "Khun B",
        "Khun C",
        "Khun D",
    };

    auto current_scene = Container::Tab({
        scene::splash(splash_brigtness),
        scene::vote(candidates, choice, screen),
        scene::error(screen, selected_scene),
    }, &selected_scene);
    auto component = Renderer(current_scene, [&] {
        if (selected_scene == 0) {
            std::raise(SIGWINCH);
            usleep(10 * 1000); // 1ms
            if (splash_brigtness > 0.0) splash_brigtness -= brightness_step;
            else selected_scene++;
        } else if (selected_scene == 1) {
            // TODO: implement checking function
        }

        return hbox({
            current_scene->Render()
        }) | border;
    });

    screen.Loop(component);
    return 0;
}
