cmake_minimum_required(VERSION 3.2.2)
cmake_policy(SET CMP0020 NEW)
cmake_policy(SET CMP0048 NEW)
cmake_policy(SET CMP0043 NEW)

project(SimpleJabber VERSION 1.0.0 LANGUAGES C CXX)

# Setting up output subdirectories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/out/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/out/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/out/lib)
foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
    string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
endforeach()

# C++ and Qt definitions
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_REQUIRED TRUE)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
add_definitions(-Wall)
add_definitions(-Werror)
find_package(Qt5Network REQUIRED)
find_package(Qt5Widgets REQUIRED)

# Components
add_subdirectory(base)
add_subdirectory(core)
add_subdirectory(ui)
include_directories(ui)

add_subdirectory(third_party EXCLUDE_FROM_ALL)
include_directories(third_party/qxmpp/src/base)
include_directories(third_party/qxmpp/src/client)


###########################################
# sjabber (shared Qt and OpenSSL libraries)
###########################################
add_executable(sjabber ${SRC})
add_dependencies(sjabber shared-third-party qxmpp-static qt5keychain)
if(MSVC)
    add_dependencies(sjabber shared-qt)
endif()
qt5_use_modules(sjabber Network Widgets)
target_link_libraries(sjabber qxmpp-static qt5keychain)
target_compile_definitions(sjabber PRIVATE QXMPP_STATIC)
