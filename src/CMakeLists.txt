cmake_minimum_required(VERSION 3.20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_executable(runMain 
    main.cpp
    Menu.cpp
    Help.cpp
    showDevelopers.cpp
    StartNewGame.cpp
    Combat.cpp
    ./Characters/Character.cpp
    ./Characters/CharacterTeam.cpp
    ./Characters/Mage.cpp
    ./Characters/Player.cpp
    ./Characters/PlayerTeam.cpp
    ./Characters/Samurai.cpp
    ./Characters/Warrior.cpp
    ./Enemies/Bandit.cpp
    ./Enemies/Enemy.cpp
    ./Enemies/EnemyTeam.cpp
    ./Enemies/Goblin.cpp
    ./Enemies/Golem.cpp
    ./Enemies/Giant.cpp
    ../Chapters/ch1.cpp
    ../Chapters/ch1Part1.cpp
    ../Chapters/ch1Part1Sub1.cpp
    ../Chapters/ch1Part1Sub2.cpp
    ../Chapters/ch1Part2.cpp
    ../Chapters/ch1Part2Sub1.cpp
    ../Chapters/ch1Part2Sub2.cpp
    ../Chapters/ch1Part3.cpp
    ../Chapters/Chapter.cpp
    ../Chapters/checkInput.cpp
    ../Chapters/SubChapter.cpp
)

target_link_libraries(runMain gtest gtest_main)
target_link_libraries(runMain)
TARGET_COMPILE_DEFINITIONS(runMain PRIVATE gtest_disable_pthreads=ON)