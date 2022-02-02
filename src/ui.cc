#include "ui.hpp"
#include "image.hpp"
#include "chain.hpp"

Component scene::splash(float &brightness) { // หน้าโชว์โลโก้
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

Component scene::vote(std::vector<std::string> &list, int &vote, ScreenInteractive &screen) { // หน้าโหวต
    // ทำตัวโชว์บล๊อกแล้วก็ตัวเลือกตามที่ design เลยครับ
    // โดยอาจจะใช้ radiobox(แนะนำ) หรือ checkbox ก็ได้
    // แล้วทำปุ่ม submit
    static auto show_choices = Radiobox(&list, &vote);
    static std::string exit_label = "Submit", reset_label = "Klear";
    static auto submit = Button(&exit_label, screen.ExitLoopClosure());
    static auto clear = Button(&reset_label, [&] {
        vote = 0;
    });
    static auto layout = Container::Vertical({
        show_choices,
        submit,
        clear,
    });
    return Renderer(layout, [&] {
        return hbox({
            vbox({
                text("Chop pleng arai?"),
                separator(),
                show_choices->Render(),
                separator(),
                hbox({
                    submit->Render(),
                    separator(),
                    clear->Render(),
                })
            }),
        });
    });
    // radiobox: https://arthursonzogni.github.io/FTXUI/examples_2component_2radiobox_8cpp-example.html
    // checkbox: https://arthursonzogni.github.io/FTXUI/examples_2component_2checkbox_8cpp-example.html
    // button: https://arthursonzogni.github.io/FTXUI/examples_2component_2gallery_8cpp-example.html (สังเหตุตรง button)
}

Component scene::error(ScreenInteractive &screen , int &sselected_scene) { // หน้า error
    static std::string exit_label = "Exit", reset_label = "Reset";
    static auto exit = Button(&exit_label, screen.ExitLoopClosure());
    static auto reset = Button(&reset_label, [&] {
        deleteChain(FILENAME);
        sselected_scene = 1;
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

Component scene::recent() { // หน้า error
    return Renderer([&] {
        return text("ABC!");
    });
    // ทำตาม design แล้วค่อยให้เรียก function ตาม user เลือกก็ได้
    // เช่น user ต้องการออกก็อาจจะใช้ exit(0); หรือต้องการ reset ก็ใช้ ...
    // exit: https://pubs.opengroup.org/onlinepubs/7908799/xsh/exit.html
}