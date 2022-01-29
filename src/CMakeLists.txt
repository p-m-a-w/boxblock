add_library (block block.cc)

if (UNIX)
  find_package (Threads)
endif (UNIX)

add_subdirectory (FTXUI)
include_directories (FTXUI/include)

add_executable (${PROJECT_NAME} main.cc block)
target_link_libraries(${PROJECT_NAME}
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)
