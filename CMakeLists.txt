cmake_minimum_required(VERSION 3.18)
include(CMakePrintHelpers)
set(CMAKE_CXX_STANDARD 17)
set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(Task_5 VERSION ${PROJECT_VERSION})

configure_file(version.h.in version.h)
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(headers)

link_directories(libs)
link_directories(${CMAKE_BINARY_DIR})

add_executable(Task_5 main.cpp)

set_target_properties(Task_5 PROPERTIES CXX_STANDARD 17 CXX_STANDARD_REQUIRED ON)
target_compile_options(Task_5 PRIVATE -Wall -Wextra -pedantic)

install(TARGETS Task_5 RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Vishnenko Maxim")

include(CPack)