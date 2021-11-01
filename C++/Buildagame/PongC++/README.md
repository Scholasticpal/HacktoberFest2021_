# Please read this for help regarding building of the project

The executable file is bundled along with the source code (see under PongC++/Debug/), that along with the SDL2.dll should be sufficient to run the game. But follow the below mentioned steps closely if you want to build from the source code.

# Requirements
This project requires Visual Studio 2019 for building. There are no such hard and fast requirements for the system.

# Gameplay
![Pong 2021-10-31 18-22-08 00_00_00-00_00_30](https://user-images.githubusercontent.com/62141759/139584669-0a7510c0-d9d1-45dd-aa43-a1425adbb944.gif)

# Steps to build
  1) Download SDL2 library from https://www.libsdl.org/download-2.0.php. 
      You can choose to download the binaries only, because that's the minimum which is required to build this game.
  2) Once files are downloaded, extract them. 
  3) Find the header files under include directory of the zip you just downloaded from SDL's website.
  4) Copy all the files and paste it under the PongC++/src/vendor/SDL2/include/ directory
  5) Run the solution (.sln) file in the root directory of the project (/PongC++/).
  6) Visual Studio opens up.
  7) Make sure you're building under architecture x86. 
  8) Press `Ctrl + Shift + B` to build. 
  9) Wait for Visual Studio to build the project.
  10) Once the project is built, Choose Local Windows Debugger or hit `F5` to run the project.
  
  That's it folks, you've succesfully built the game, hope you enjoy playing!
  
  **PS**: This is not complete game, the sound effects and score mechanism and losing mechansim are yet to be added. You can add them yourself if you wish... 😄😄

  
