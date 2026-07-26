cmake_minimum_required(VERSION 3.16)
project(MyApp)

# Encuentra SFML (asegúrate de que apunte a tu SDK/NDK o ruta de SFML)
find_package(SFML 3.0 COMPONENTS graphics window system REQUIRED) # O la versión 2.6 según uses

add_executable(MyApp
    app/src/main/cpp/main.cpp
)

# Enlaza las librerías de SFML y OBLIGATORIAMENTE las del sistema Android para gráficos
target_link_libraries(MyApp PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    EGL
    GLESv2
    android
    log
)
