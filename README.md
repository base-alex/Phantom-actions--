# Phantom

Fully C++ Minecraft injection client for linux. Mapping code is based off of
[UDP](https://github.com/UnknownDetectionParty/UDP-CPP), and [Dear ImGui](https://github.com/ocornut/imgui) is used
for the window, but the cheats and stuff are my own. 

### Different MC Versions

By default, Phantom is configured to build for version 1.8.9 forge. At this point in time, forge is not supported. To
change the target minecraft version, edit the `Platform.h` file in the `src` directory.

### Building

To build, make sure you have cmake installed, as well as a JDK. I was having issues with openjdk 1.8, I would recommend 
using the latest version of openjdk. Cmake will automatically find the files associated and link with them. You also
need the development headers for SDL2 and OpenGL.

### Injecting into Minecraft

To inject, you need some form of shader object injector for linux. I use [injector](https://github.com/kubo/injector).

