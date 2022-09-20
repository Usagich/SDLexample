# SDLexample

[![CMake](https://github.com/ngagesdk/SDLexample/actions/workflows/cmake.yml/badge.svg)](https://github.com/ngagesdk/SDLexample/actions/workflows/cmake.yml)

A simple [SDL 2.0.x](https://github.com/libsdl-org/SDL) sample/template
project.

## Compiling

### Windows

The easiest way to get SDLexample up and running is Visual Studio 2022
with [C++ CMake tools for
Windows](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio)
installed.  Simply open the cloned repository via `File -> Open ->
Folder`.  Everything else is set up automatically.

### Nokia N-Gage

The procedure for the Nokia N-Gage is the same as for Windows. You only
need to install and set up the [N-Gage
SDK.](https://github.com/ngagesdk/ngage-toolchain) in advance and select
the respective build configuration within Visual Studio.

Please note: In order for the SDL executable to be executed properly by
the launcher, the path in the file
[ngage_appui.cpp](src/ngage_appui.cpp) file must be adjusted
accordingly.  Unfortunately, I have not yet found a way to configure
this dynamically.

### Linux

SDLexample can also be compiled on Linux with the included CMake
configuration.  All required dependencies are fetched at compile time.

```bash
mkdir build
cd build
cmake ..
make
````

## License and Credits

This project is under [public domain](http://creativecommons.org/publicdomain/zero/1.0/).

To the extent possible under law, Michael Fitzmayer has waived all
copyright and related or neighboring rights to SDLexample.  This work is
published from: Germany.
