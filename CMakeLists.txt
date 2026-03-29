cmake_minimum_required(VERSION 3.28)
project(rangers-sdk VERSION 0.1.8
                   DESCRIPTION "An SDK for Sonic Frontiers"
                   LANGUAGES CXX ASM_MASM)

# Temporary workaround for bug, see
# - https://discourse.cmake.org/t/building-lib-file-from-asm-cmake-bug/1959
# - https://gitlab.kitware.com/cmake/cmake/-/issues/18889
set(CMAKE_ASM_MASM_CREATE_STATIC_LIBRARY "<CMAKE_AR> /OUT:<TARGET> <LINK_FLAGS> <OBJECTS>")

set(UCSL_EIGEN_MATH ON)

include(FetchContent)
FetchContent_Declare(universal-cslib GIT_REPOSITORY https://github.com/angryzor/universal-cslib.git GIT_TAG v1.0.53 FIND_PACKAGE_ARGS)
FetchContent_MakeAvailable(universal-cslib)

add_library(rangers-sdk STATIC)
target_link_libraries(rangers-sdk PUBLIC universal-cslib)
target_compile_features(rangers-sdk PUBLIC cxx_std_20)
target_include_directories(rangers-sdk PUBLIC rangers-api vendor/bullet3/src)
target_sources(rangers-sdk
    PRIVATE
        src/thunks.asm
    PUBLIC FILE_SET HEADERS BASE_DIRS include FILES
        include/rangers-sdk.h
)
