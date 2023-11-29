cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
add_subdirectory(googletest)

add_executable(runAllTests
    testEnemyClass.cpp
    testGoblinClass.cpp
    testBanditClass.cpp
    testEnemyTeamClass.cpp
    testCharacterClass.cpp
    testCharacterTeamClass.cpp
    testSamuraiClass.cpp
    testPlayerClass.cpp
    testshowDevelopers.cpp
    testHelpClass.cpp
)

target_link_libraries(runAllTests gmock gtest gtest_main)
target_link_libraries(runAllTests)
TARGET_COMPILE_DEFINITIONS(runAllTests PRIVATE gtest_disable_pthreads=ON)