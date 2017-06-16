# Sets CMake policies and output directories.
macro(initial_cmake_setup)
    cmake_policy(SET CMP0020 NEW)
    cmake_policy(SET CMP0048 NEW)
    cmake_policy(SET CMP0043 NEW)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/bin)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out/lib)
    foreach(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
        string(TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG)
        set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
        set(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})
        set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
    endforeach()
endmacro()

# Adds component from ${name} subdirectory as static library 'sj-${name}'.
macro(add_component name)
    add_subdirectory(${name} EXCLUDE_FROM_ALL)
    add_library(sj-${name} STATIC EXCLUDE_FROM_ALL ${${name}-src})
    target_compile_options(sj-${name} PUBLIC -Wall -Wextra -Werror)
    target_include_directories(sj-${name} PUBLIC ${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
endmacro()

# Set option for subdirectory even if other value was cached already.
macro(set_option name value)
    set(${name} ${value} CACHE INTERNAL "" FORCE)
endmacro()

# Links specified Qt5 package to target.
macro(target_qt5_package target package)
    find_package(Qt5${package} REQUIRED)
    qt5_use_modules(${target} ${package})
endmacro()
