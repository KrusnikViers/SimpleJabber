cmake_minimum_required(VERSION 3.2.2)
project(SimpleJabber VERSION 0.1.0 LANGUAGES C CXX)

cmake_policy(SET CMP0020 OLD)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0043 NEW)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/exe)
set(PROJECT_BINARY_DIR ${EXECUTABLE_OUTPUT_PATH})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

# C++ and Qt definitions
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_REQUIRED TRUE)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
find_package(Qt5Network REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Project components
add_subdirectory(base)
add_subdirectory(core)
add_subdirectory(ui)
include_directories(ui)

# Third-party components
add_subdirectory(third_party)

# Include QXmpp as part of the project
include_directories(third_party/qxmpp/src/base)
include_directories(third_party/qxmpp/src/client)
include_directories(third_party/qxmpp/src/server)

# SJabber (shared Qt and OpenSSL libraries)
add_executable(sjabber ${SRC})
add_dependencies(sjabber qxmpp-static shared-third-party)

qt5_use_modules(sjabber Network Widgets)
target_link_libraries(sjabber qxmpp-static)
target_compile_definitions(sjabber PRIVATE QXMPP_STATIC)
