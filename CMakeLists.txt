cmake_minimum_required(VERSION 2.8)
project (simple-jabber)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_REQUIRED TRUE)

set(SJABBER_MAJOR_VERSION 0)
set(SJABBER_MINOR_VERSION 1)
set(SJABBER_PATCH_VERSION 0)
set(SJABBER_VERSION
  ${SJABBER_MAJOR_VERSION}.${SJABBER_MINOR_VERSION}.${SJABBER_PATCH_VERSION})

set(project_dir ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${project_dir}/build/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${project_dir}/build/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${project_dir}/build/bin)

add_executable(simple-jabber main.cpp)