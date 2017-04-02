cmake_minimum_required(VERSION 2.8.11)
cmake_policy(SET CMP0020 OLD)
cmake_policy(SET CMP0048 NEW)

# Project
project(sjabber VERSION 0.1.0 LANGUAGES C CXX)
set(project_dir ${CMAKE_CURRENT_SOURCE_DIR})

# C++ definitions
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_REQUIRED TRUE)

# Qt definitions
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
find_package(Qt5Widgets REQUIRED)

# Files from root directory
set(SRC
    main.cpp)

# Components
add_subdirectory(base)
add_subdirectory(ui)

# Build
add_executable(sjabber ${SRC})
qt5_use_modules(sjabber Widgets)
target_compile_definitions(sjabber PRIVATE VER_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(sjabber PRIVATE VER_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(sjabber PRIVATE VER_PATCH=${PROJECT_VERSION_PATCH})
target_compile_definitions(sjabber PRIVATE VER_FULL=${PROJECT_VERSION})
