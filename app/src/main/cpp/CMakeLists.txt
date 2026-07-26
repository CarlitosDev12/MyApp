cmake_minimum_required(VERSION 3.16)
project(MyApp)

find_package(SFML 3.0 COMPONENTS graphics window system REQUIRED)

add_executable(MyApp
    main.cpp
)

target_link_libraries(MyApp PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    EGL
    GLESv2
    android
    log
)
