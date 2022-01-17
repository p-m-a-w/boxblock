add_library (block block.cc)

add_subdirectory (json)
include_directories (json/include)

add_subdirectory (FTXUI)
include_directories (FTXUI/include)

add_executable (${PROJECT_NAME} main.cc block)
target_link_libraries(${PROJECT_NAME}
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
