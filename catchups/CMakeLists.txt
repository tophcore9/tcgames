cmake_minimum_required(VERSION 3.20)
project(catchups C)

set(CMAKE_C_STANDARD 11)

add_executable(cathups main.c
        map.c
        hero.c
        feed.c
        init.c
        game.c
        menu.c
        enemy.c
)
