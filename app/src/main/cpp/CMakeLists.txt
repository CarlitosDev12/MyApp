cmake_minimum_required(VERSION 3.22.1)
project(MyApp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED 20)

# 1. Indicar dónde están los archivos .hpp de SFML
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

# 2. Definir la ruta de las librerías según la arquitectura actual
set(SFML_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

# 3. Verificar si existen los binarios para esta arquitectura específica
if(EXISTS "${SFML_LIB_DIR}/libsfml-graphics.so")
    add_library(sfml-graphics SHARED IMPORTED)
    set_target_properties(sfml-graphics PROPERTIES IMPORTED_LOCATION ${SFML_LIB_DIR}/libsfml-graphics.so)

    add_library(sfml-window SHARED IMPORTED)
    set_target_properties(sfml-window PROPERTIES IMPORTED_LOCATION ${SFML_LIB_DIR}/libsfml-window.so)

    add_library(sfml-system SHARED IMPORTED)
    set_target_properties(sfml-system PROPERTIES IMPORTED_LOCATION ${SFML_LIB_DIR}/libsfml-system.so)

    add_library(sfml-audio SHARED IMPORTED)
    set_target_properties(sfml-audio PROPERTIES IMPORTED_LOCATION ${SFML_LIB_DIR}/libsfml-audio.so)

    add_library(sfml-network SHARED IMPORTED)
    set_target_properties(sfml-network PROPERTIES IMPORTED_LOCATION ${SFML_LIB_DIR}/libsfml-network.so)
endif()

# 4. Agregar tu ejecutable nativo
add_executable(MyApp
    main.cpp
)

# 5. Vincular las librerías
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
