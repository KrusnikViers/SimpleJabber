cmake_minimum_required(VERSION 2.8.11)
cmake_policy(SET CMP0020 OLD)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0043 NEW)

# Project settings
project(sjabber VERSION 0.1.0 LANGUAGES C CXX)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/exe)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# C++ and Qt definitions
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_REQUIRED TRUE)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Sql REQUIRED)

# Current directory sources
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(SRC main.cpp)

# Components
add_subdirectory(base)
add_subdirectory(core)
add_subdirectory(ui)
add_subdirectory(third_party/qxmpp)

# Build
add_executable(sjabber ${SRC})
qt5_use_modules(sjabber Widgets Sql)
target_link_libraries(sjabber qxmpp)
target_compile_definitions(sjabber PRIVATE VER_MAJOR=${PROJECT_VERSION_MAJOR})
target_compile_definitions(sjabber PRIVATE VER_MINOR=${PROJECT_VERSION_MINOR})
target_compile_definitions(sjabber PRIVATE VER_PATCH=${PROJECT_VERSION_PATCH})
target_compile_definitions(sjabber PRIVATE VER_FULL=${PROJECT_VERSION})
target_compile_definitions(sjabber PRIVATE QXMPP_STATIC)
