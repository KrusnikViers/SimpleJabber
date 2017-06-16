# Base sources allowed to include only third-party source files.

set(base-src
    ${CMAKE_CURRENT_SOURCE_DIR}/connection_types.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/connection_types.h
    ${CMAKE_CURRENT_SOURCE_DIR}/project_info.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/project_info.h
    ${CMAKE_CURRENT_SOURCE_DIR}/user_types.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/user_types.h
    PARENT_SCOPE)
