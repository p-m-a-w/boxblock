#pragma once
#include "chain.hpp"
#include "ftxui/component/component.hpp"
#include "ftxui/component/screen_interactive.hpp"
#define _WIDTH  100
#define _HEIGHT 100
using namespace ftxui;

typedef struct {
    ScreenInteractive *screen;
    int *selected_scene;
    int *vote;
} SceneConfiguration;

namespace Scene {
    Component splash(float &brightness); // หน้าโชว์โลโก้
    Component vote(SceneConfiguration &config, const vector<std::string> &list, vector<block> &chain); // หน้าโหวต
    Component error(SceneConfiguration &config,vector<block> &chain); // หน้า error
    Component summary(SceneConfiguration &config, const vector<std::string> &list, const vector<block> &chain);
}
// }