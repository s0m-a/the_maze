THE MAZE GAME

The Maze Game is a first-person 3D maze game reminiscent of classics like Wolfenstein or Doom, focusing on exploration without enemies or weapons, although these features may be incorporated in future updates. Developed using SDL2 and C, it employs raycasting to simulate the illusion of a 3D maze environment. The game is compatible with Mac OS X and Linux/Ubuntu platforms.

PROJECT OVERVIEW
The Maze Game was crafted in C utilizing the SDL2 library. Development primarily took place on Ubuntu 14.04 LTS, using gcc (Ubuntu 4.8.4-2ubuntu1~14.04) 4.8.4 compiler.

About SDL2 💻
SDL2, or Simple DirectMedia Layer, is a versatile cross-platform development library offering low-level access to audio, keyboard, mouse, joystick, and graphics hardware through OpenGL and Direct3D. Widely employed in video playback software, emulators, and numerous popular games, SDL2 is renowned for its flexibility and performance.

SYSTEM REQUIREMENT
Operating System: Mac OS X or Linux/Ubuntu
SDL2 Library
Installation Instructions
If SDL2 is not already installed, you can obtain it using the provided installation script. Simply download the script from <a href="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/graphics_programming/install_SDL2.sh">here</a> and execute the following commands in your terminal:
$ ls
install_SDL2.sh
$ chmod 755 install_SDL2.sh
$ sudo ./install_SDL2.sh
Following these steps ensures a smooth and hassle-free installation of SDL2, enabling you to enjoy The Maze Game seamlessly.




##Getting Started

1. Clone the Repository
Start by cloning the repository to your local machine using the following command:
git clone https://github.com/s0m-a/the_maze.git

2. Compile the Source Code
" gcc -g -Wall -Werror -Wextra -pedantic \
    -I/usr/local/include/SDL2 \
    -L/usr/lib/x86_64-linux-gnu \
    -lSDL2 -lm \
  ./src/*.c \
   -o maze "

3. Run the Game
./maze maps/map_1

Some basic maps are provided in this repo in the maps/ directory, but you can make your own maps to play as well.
And run it:
  ./maze maps/"name of the map file you created"

##Gameplay Instructions

Navigate through the maze using the arrow keys or ASWE keys. Use left and right arrows (or A and D keys) to rotate the player, and up and down arrows (or W and S keys) to move forward or backward.

By default, the player's starting position and the maze's end goal are determined by the map file. If not specified, the player starts at the top left corner and the goal is located in the last accessible space in the file.

## Map Creation
Refer to the files in the maps/ directory for examples of the maze file format compatible with the game. Different characters represent various elements such as walls, floor, player position, and goal.

Here's a breakdown of the characters' meanings within the game:

**Map File Characters' in Game Meanings**
0: Denotes a floor or walkable space.
1: Represents a red wall.
2: Indicates a green wall.
3: Represents a blue wall.
4: Indicates a yellow wall.
p: Specifies the player's starting position.

## Reference
- [lodev.org](https://lodev.org/cgtutor/raycasting.html)
- [youtube](https://www.youtube.com/watch?v=ebzlMOw79Yw)
- [developer](https://devforum.roblox.com/t/understanding-raycasting/2637244)
- [permadi.com](https://permadi.com/1996/05/ray-casting-tutorial-1/)
- [cplusplus.com](https://cplusplus.com/forum/beginner/214311/)
- [make your own Raycaster](https://www.youtube.com/watch?v=gYRrGTC7GtA)
- [pikuma.com](https://pikuma.com/courses/raycasting-engine-tutorial-algorithm-javascript)

##AUTHOR
[Github](https://github.com/s0m-a/the_maze) | [Linkedin](www.linkedin.com/in/nmesoma-anita-77b677293)

##Licensing Information
This project operates under the MIT License. For detailed terms, refer to the LICENSE file.

##Gratitude and Recognition 🙏
The creation of this project was made possible through the collaborative efforts of individuals within the Alx-Africa community. Alx-Africa offers a comprehensive full-stack software engineering curriculum delivered remotely, equipping students with the skills and knowledge necessary for thriving careers in the tech industry. To learn more about Alx-Africa, visit this link.

##ALX Staff: Their invaluable assistance, guidance, and provision of resources were instrumental in the development of this project and throughout the entire curriculum.
Cohort 16 and Fellow ALX Students: I extend my heartfelt gratitude for your camaraderie, support, and shared insights throughout our jounery.

Thank you for taking the time to explore this documentation and experience The Game. Your engagement is sincerely appreciated, and I hope you found enjoyment in the journey!









