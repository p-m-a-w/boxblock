#include "ui.hpp"
#include "image.hpp"

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
    static std::string submit_label = "Submit", clear_label = "Klear";
    static auto submit = Button(&submit_label, screen.ExitLoopClosure());
    static auto clear = Button(&clear_label, [&] {
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

Component scene::error(ScreenInteractive &screen) { // หน้า error
    return Renderer([&] {
        return text("ABC!");
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