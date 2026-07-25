cmake_minimum_required(VERSION 3.18.1)
project("myapp")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Ruta donde están las librerías .so de SFML
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

# Definir las librerías precompiladas de SFML
add_library(sfml-system SHARED IMPORTED)
set_target_properties(sfml-system PROPERTIES IMPORTED_LOCATION ${SFML_DIR}/libsfml-system.so)

add_library(sfml-window SHARED IMPORTED)
set_target_properties(sfml-window PROPERTIES IMPORTED_LOCATION ${SFML_DIR}/libsfml-window.so)

add_library(sfml-graphics SHARED IMPORTED)
set_target_properties(sfml-graphics PROPERTIES IMPORTED_LOCATION ${SFML_DIR}/libsfml-graphics.so)

# Definir la librería principal que busca NativeActivity (libmain.so)
add_library(main SHARED main.cpp)

target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Enlazar todo con Android
target_link_libraries(main
    sfml-graphics
    sfml-window
    sfml-system
    android
    log
)

