add_library (block block.cc)

if (UNIX)
  find_package (Threads)
endif (UNIX)

set (FTXUI_BUILD_TESTS false)
set (FTXUI_BUILD_EXAMPLES false)
set (FTXUI_BUILD_DOCS false)
add_subdirectory (FTXUI)
include_directories (FTXUI/include)

add_executable (${PROJECT_NAME} main.cc block chain.cc ui.cc interface.cc)
target_link_libraries(${PROJECT_NAME}
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
