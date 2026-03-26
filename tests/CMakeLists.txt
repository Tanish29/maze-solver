cmake_minimum_required(VERSION 3.16)

# fetch catch2
include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.8.1 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# create test executable
file(GLOB TEST_FILES CONFIGURE_DEPENDS "*.cpp")

add_executable(tests ${TEST_FILES})

target_link_libraries(
    tests
    PRIVATE
        Catch2::Catch2WithMain
        maze_lib
)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(tests)
