#include "ui.hpp"
#include "image.hpp"
#include "interface.hpp"

Component Scene::splash(float &brightness) { // หน้าโชว์โลโก้
    return Renderer([&] {
        auto c = Canvas(WIDTH, HEIGHT);
        for (int x = 0; x < WIDTH; ++x) {
            for (int y = 0; y < HEIGHT; ++y) {
                unsigned char color = SPLASH[y][x] * brightness;
                if (color != 0) c.DrawPoint(x, (y * 2) - (HEIGHT / 2), true, Color(color, color, color));
            }
        }
        return canvas(std::move(c));
    });
}

Component Scene::vote(SceneConfiguration &config, const std::vector<std::string> &list, vector<block> &chain) { // หน้าโหวต
    // ทำตัวโชว์บล๊อกแล้วก็ตัวเลือกตามที่ design เลยครับ
    // โดยอาจจะใช้ radiobox(แนะนำ) หรือ checkbox ก็ได้
    // แล้วทำปุ่ม submit
    static auto show_choices = Radiobox(&list, config.vote);
    static std::string submit_label = "Submit", exit_label = "Exit";
    static auto submit = Button(&submit_label, [&] {
        submitVote(*(config.vote), chain);
    });
    static auto exit = Button(&exit_label, config.screen->ExitLoopClosure());
    static auto layout = Container::Vertical({
        show_choices,
        submit,
        exit,
    });
    return Renderer(layout, [&] {
        return hbox({
            vbox({
                text("Who would you like to vote?"),
                separator(),
                show_choices->Render(),
                separator(),
                hbox({
                    submit->Render(),
                    separator(),
                    exit->Render(),
                })
            }),
        });
    });
    // radiobox: https://arthursonzogni.github.io/FTXUI/examples_2component_2radiobox_8cpp-example.html
    // checkbox: https://arthursonzogni.github.io/FTXUI/examples_2component_2checkbox_8cpp-example.html
    // button: https://arthursonzogni.github.io/FTXUI/examples_2component_2gallery_8cpp-example.html (สังเหตุตรง button)
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
        return hbox({
            vbox({
                text("Invalid Chain"),
                text("Do you want to reset the Chain?"),
                separator(),
                hbox({
                    reset->Render(),
                    separator(),
                    exit->Render(),
                })
            }),
        });
    });
    // ทำตาม design แล้วค่อยให้เรียก function ตาม user เลือกก็ได้
    // เช่น user ต้องการออกก็อาจจะใช้ exit(0); หรือต้องการ reset ก็ใช้ ...
    // exit: https://pubs.opengroup.org/onlinepubs/7908799/xsh/exit.html
}

Component Scene::summary(SceneConfiguration &config, const std::vector<std::string> &list, const vector<block> &chain) {
    static vector<int>count = countVote(chain);
    static int n = 0;
    for (const auto &b : count)
        n = n+b;
    static vector<Component> components;
    for (int i = 0; i<5 ; i++ )
        components.push_back(Slider(list[i],&count[i],0,n,0));
    static auto layout = Container::Vertical({
        components[0],
        components[1],
        components[2],
        components[3],
        components[4],
    });
    return Renderer(layout, [&] {
        return vbox({  
            components[0]->Render(),
            components[1]->Render(),
            components[2]->Render(),
            components[3]->Render(),
            components[4]->Render(),
        });
    });
    // ทำตาม design แล้วค่อยให้เรียก function ตาม user เลือกก็ได้
    // เช่น user ต้องการออกก็อาจจะใช้ exit(0); หรือต้องการ reset ก็ใช้ ...
    // exit: https://pubs.opengroup.org/onlinepubs/7908799/xsh/exit.html
}
