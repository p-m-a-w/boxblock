#include <thread>
#include <cstdlib>
#include <csignal>
#include <unistd.h>
#include "ui.hpp"
#include "ftxui/component/screen_interactive.hpp"

using namespace ftxui;

int main(int argc, const char* argv[]) {
    float splash_brigtness = 1.0;
    int selected_scene = 1;
    auto scenes = Container::Tab({
        scene::splash(splash_brigtness),
        scene::vote(),
    }, &selected_scene);

    auto component = Renderer([&] {
        if (selected_scene == 1) {
            std::raise(SIGWINCH);
            if (splash_brigtness >= 0.0) splash_brigtness -= 10.0 / 1618.0;
            usleep(10 * 1000); // 10ms
        } else if (selected_scene == 2) {
            // TODO: next scene go here
        }
        return hbox({
            scenes->Render()
        }) | border;
    });

    auto screen = ScreenInteractive::FitComponent();
    screen.Loop(component);
    return 0;
}
