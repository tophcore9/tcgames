# tcgames

This is a collection of simple games in C.
There are games that already have been created:
+ Catchups (now available only in Windows)
---
# How to build
+ Download current version of CMake https://cmake.org/download/
+ Download the compiler. I use gcc (actually MinGW-w64 https://www.mingw-w64.org)
+ Clone repository and select the game you want to build 
+ Make a 'build' directory (```mkdir build```)
+ Change to it (```cd build```)
+ Configure the project with CMake (```cmake -G "<your compiler>" ..```)
+ Build the project (```cmake --build .```)
+ Open the executable file. It names the same as the game that you have chosen
+ Enjoy!
---
# License
This project is developed under the BSD-3-Clause license.
