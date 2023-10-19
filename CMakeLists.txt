cmake_minimum_required(VERSION 3.21.3)
SET(CMAKE_C_COMPILER gcc)
SET(CMAKE_CXX_COMPILER g++)

project(tinygame)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pages
)

set(SOURCE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/application.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pages/game_page.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pages/splash.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/player.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pages/lobby.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/board.cpp
)

add_executable(app ${SOURCE})
