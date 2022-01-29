#include "ui.hpp"

void scene::splash() { // หน้าโชว์โลโก้
    // ใช้ canvas ของ FTXUI สร้างตัวหนังสือ BoxBlock ขึ้นมาก็ได้ครับ
    // แล้วอาจจะใช้ sleep(int) ในการลดความเข้มตัวหนังสือให้เหลือแต่พื้นดำ
    // canvas: https://github.com/ArthurSonzogni/FTXUI/blob/master/examples/dom/canvas.cpp
    // sleep: https://www.softwaretestinghelp.com/cpp-sleep/
}

void scene::vote() { // หน้าโหวต
    // ทำตัวโชว์บล๊อกแล้วก็ตัวเลือกตามที่ design เลยครับ
    // โดยอาจจะใช้ radiobox(แนะนำ) หรือ checkbox ก็ได้
    // แล้วทำปุ่ม submit
    // radiobox: https://arthursonzogni.github.io/FTXUI/examples_2component_2radiobox_8cpp-example.html
    // checkbox: https://arthursonzogni.github.io/FTXUI/examples_2component_2checkbox_8cpp-example.html
    // button: https://arthursonzogni.github.io/FTXUI/examples_2component_2gallery_8cpp-example.html (สังเหตุตรง button)
}

void scene::error() { // หน้า error
    // ทำตาม design แล้วค่อยให้เรียก function ตาม user เลือกก็ได้
    // เช่น user ต้องการออกก็อาจจะใช้ exit(0); หรือต้องการ reset ก็ใช้ ...
    // exit: https://pubs.opengroup.org/onlinepubs/7908799/xsh/exit.html
}