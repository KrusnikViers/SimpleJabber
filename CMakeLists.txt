cmake_minimum_required(VERSION 3.2.2)
include(CMakeDefinitions.cmake)
initial_cmake_setup()

# Main project.
project(SimpleJabber VERSION 1.0.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_REQUIRED TRUE)


# Third-party dependencies: qxmpp, qt5keychain, shared-third-party.
add_subdirectory(third_party EXCLUDE_FROM_ALL)


# Components (files added to <component_name>_src variable).
add_component(base)
set_target_properties(sj-base PROPERTIES AUTOMOC ON)
target_link_libraries(sj-base qxmpp qt5keychain)
target_qt5_package(sj-base Network)

add_component(core)
set_target_properties(sj-core PROPERTIES AUTOMOC ON)
target_link_libraries(sj-core sj-base)

add_component(ui)
set_target_properties(sj-ui PROPERTIES AUTOMOC ON AUTOUIC ON)
target_link_libraries(sj-ui sj-core)
target_qt5_package(sj-base Widgets)


# Main executable.
add_executable(sj-client main.cpp)
add_dependencies(sj-client shared-third-party)
target_link_libraries(sj-client sj-ui)
