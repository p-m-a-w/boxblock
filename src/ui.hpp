#pragma once
#include "ftxui/component/component.hpp"
#define WIDTH  100
#define HEIGHT 100
using namespace ftxui;
namespace scene {
    Component splash(float &brightness); // หน้าโชว์โลโก้
    Component vote(); // หน้าโหวต
    Component error(); // หน้า error
    Component recent();
}