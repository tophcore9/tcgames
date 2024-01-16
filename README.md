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
# Rules
+ Your aim is to eat as much tasty feeds as possible but you have an enemy who will get in your way. 
+ You can avoid it but it's not as easy as you thought.
+ The enemy is faster than you and can move 1 or 2 spaces towards you (you can only move 1 space).
+ You can deceive your enemy if you are opposite him. Just walk in his direction and he will not have time to react.
---
# Controls
### Menu
+ 'W' or 'w' to select an item above
+ 'S' or 's' to select an item below

### Game
+ 'W' or 'w' to go up
+ 'A' or 'a' to go left
+ 'S' or 's' to go down
+ 'D' or 'd' to go right
+ 'esc' to leave
---

# License
This project is developed under the BSD-3-Clause license.
