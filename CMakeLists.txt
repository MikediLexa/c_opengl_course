cmake_minimum_required(VERSION 3.10)
project(@PROJECT_NAME@)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

# Catch2 über FetchContent einbinden
include(FetchContent)
FetchContent_Declare(
  catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG v3.5.4
)
FetchContent_MakeAvailable(catch2)

# Tests
file(GLOB TEST_SOURCES "tests/*.cpp")
add_executable(tests ${TEST_SOURCES} ${SOURCES})
target_link_libraries(tests Catch2::Catch2WithMain)

enable_testing()
include(CTest)
add_test(NAME AllTests COMMAND $<TARGET_FILE:tests>)
