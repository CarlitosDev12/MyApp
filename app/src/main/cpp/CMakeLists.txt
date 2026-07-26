cmake_minimum_required(VERSION 3.22.1)
project(MyApp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

# 1. Indicarle a CMake dónde están tus archivos .hpp de SFML locales
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 2. Agregar tu ejecutable nativo apuntando a tu archivo principal de C++
add_executable(MyApp
    main.cpp
)

# 3. Vincular todos los módulos de SFML y las librerías obligatorias de Android
target_link_libraries(MyApp PRIVATE
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    sfml-network
    EGL
    GLESv2
    android
    log
)
