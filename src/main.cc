#include <string>                 // for getchar
#include <cmath>                   // for cos
#include <ftxui/dom/elements.hpp>  // for Fit, canvas, operator|, border, Element
#include <ftxui/screen/screen.hpp>  // for Pixel, Screen
#include <vector>                   // for vector, allocator
#include <cstdio>


#include "ftxui/component/component.hpp"  // for Renderer, CatchEvent, Horizontal, Menu, Tab
#include "ftxui/component/component_base.hpp"      // for ComponentBase
#include "ftxui/component/event.hpp"               // for Event
#include "ftxui/component/mouse.hpp"               // for Mouse
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive
#include "ftxui/dom/canvas.hpp"                    // for Canvas
#include "ftxui/screen/color.hpp"  // for Color, Color::Red, Color::Blue, Color::Green, ftxui
#include "ftxui/dom/node.hpp"      // for Render

#include <unistd.h>
#include <csignal>
#include "image.hpp"

using namespace ftxui;
void drawBlockBox(Canvas &c, float brigtness) {
    for (int x = 0; x < 100; ++x) {
        for (int y = 0; y < 100; ++y) {
            unsigned char color = SPLASH[y][x] * brigtness;
            if (color != 0) c.DrawPoint(x, (y * 2) - 50, true, Color(color, color, color));
        }
    }
}

Element drawpp(Canvas &c) {
    //c.DrawText(30, 30, "Vote");
    std::vector<std::string> radiobox_list = {
      "Use gcc",
      "Use clang",
      "Use emscripten",
      "Use tcc",
  };
  int selected = 0;
  auto x = Radiobox(&radiobox_list, &selected);
  return hbox({
      x->Render(),
    //   separator(),
    //   c->Render(),
  });
}

int main(int argc, const char* argv[]) {

    auto c = Canvas(100, 100);

    auto document = canvas(&c) | border;

    int k = 1;
    auto comp = Renderer([&] {
        // drawBlockBox(c, 1.0);
        

        return drawpp(c);
    });
    

    auto screen = ScreenInteractive::TerminalOutput();
    screen.Loop(comp);
    return 0;
}

// Copyright 2020 Arthur Sonzogni. All rights reserved.
// Use of this source code is governed by the MIT license that can be found in
// the LICENSE file.