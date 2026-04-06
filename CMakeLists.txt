cmake_minimum_required(VERSION 4.1)
project(flappyBird)

set(CMAKE_CXX_STANDARD 20)

set(SFML_DIR "/usr/local/opt/sfml")

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

add_executable(flappyBird main.cpp)

target_link_libraries(flappyBird
        sfml-graphics
        sfml-window
        sfml-system
)

