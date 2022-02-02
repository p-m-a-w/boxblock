#pragma once
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#define WIDTH  100
#define HEIGHT 100
using namespace ftxui;
namespace scene {
    Component splash(float &brightness); // หน้าโชว์โลโก้
    Component vote(std::vector<std::string> &list, int &vote, ScreenInteractive &screen); // หน้าโหวต
    Component error(ScreenInteractive &screen); // หน้า error
    Component recent();
}