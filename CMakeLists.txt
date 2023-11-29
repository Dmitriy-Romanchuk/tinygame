cmake_minimum_required(VERSION 3.21.3)
SET(CMAKE_CXX_COMPILER g++)

project(tinygame)

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/pages
)

find_package(Curses REQUIRED)
set(CURSES_CFLAGS "${CURSES_CFLAGS} -lncurses -DNCURSES_STATIC")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CURSES_CFLAGS}")

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

set_property(TARGET app PROPERTY CXX_STANDARD 20)

target_link_libraries(app ${CURSES_LIBRARY})

