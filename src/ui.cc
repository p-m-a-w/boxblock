#include "ui.hpp"
#include "image.hpp"
#include "interface.hpp"
#include <unistd.h>

Component Scene::splash(float &brightness) { // หน้าโชว์โลโก้
    return Renderer([&] {
        auto c = Canvas(_WIDTH, _HEIGHT);
        for (int x = 0; x < _WIDTH; ++x) {
            for (int y = 0; y < _HEIGHT; ++y) {
                unsigned char color = SPLASH[y][x] * brightness;
                if (color != 0) c.DrawPoint(x, (y * 2) - (_HEIGHT / 2), true, Color(color, color, color));
            }
        }
        return canvas(std::move(c));
    });
}

Component Scene::vote(SceneConfiguration &config, const std::vector<std::string> &list, vector<block> &chain) {
    static auto show_choices = Radiobox(&list, config.vote);
    static std::string submit_label = "Submit", exit_label = "Exit";
    static auto submit = Button(&submit_label, [&] {
        submitVote(*(config.vote), chain);
        *(config.selected_scene) = 3;
    });
    static auto exit = Button(&exit_label, config.screen->ExitLoopClosure());
    static auto layout = Container::Vertical({
        show_choices,
        submit,
        exit,
    });
    return Renderer(layout, [&] {
        return vbox({
            text("Who would you like to vote?") | hcenter,
            separator(),
            show_choices->Render() | hcenter,
            separator(),
            hbox({
                submit->Render(),
                exit->Render(),
            }) | hcenter,
        }) | size(WIDTH, EQUAL, _WIDTH);
    });
}

Component Scene::error(SceneConfiguration &config,vector<block> &chain) { // หน้า error
    static std::string exit_label = "Exit", reset_label = "Reset";
    static auto exit = Button(&exit_label, config.screen->ExitLoopClosure());
    static auto reset = Button(&reset_label, [&] {
        deleteChain(FILENAME);
        createChainFile(FILENAME,{});
        importChain(FILENAME,chain);
        *config.selected_scene = 1;
    });
    static auto layout = Container::Horizontal({
        reset,
        exit,
    });
    return Renderer(layout, [&] {
        return vbox({
            text("Invalid Chain") | hcenter,
            text("Do you want to reset the Chain?") | hcenter,
            separator(),
            hbox({
                reset->Render(),
                exit->Render(),
            }) | hcenter
        }) | size(WIDTH, EQUAL, _WIDTH);
    });
}

Element result_bar(string title, float x) {
    return hbox({
        text(title) | size(WIDTH, EQUAL, 10) | hcenter,
        separator(),
        gauge(x),
    }) | size(WIDTH, EQUAL, _WIDTH);
}

Component Scene::summary(SceneConfiguration &config, const std::vector<std::string> &list, const vector<block> &chain) {
    static int n = 0;
    static vector<Element> elements;
    static string back_label("Back");
    static auto back = Button(&back_label, [&] {
        *config.selected_scene = 1;
    });
    static vector<int> count = countVote(chain);
    for (const auto &b : count)
        n = n+b;
    for (int i = 0; i<5 ; i++ )
        elements.push_back(result_bar(list[i], 0.5));

    return Renderer(back, [&] {
        n = 0;
        count = countVote(chain);
        for (const auto &b : count)
            n = n+b;
        for (int i = 0; i<5 ; i++ )
            elements[i] = result_bar(list[i], (float)count[i] / n);
        usleep(5 * 1000); // sleep for 5ms

        return vbox({ 
            elements[0],
            separator(),
            elements[1],
            separator(),
            elements[2],
            separator(),
            elements[3],
            separator(),
            elements[4],
            separator(),
            back->Render() | hcenter
        });
    });
}
