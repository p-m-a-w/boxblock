add_library (block block.cc)

add_subdirectory (json)
include_directories (json/include)

add_executable (boxblock main.cc block)