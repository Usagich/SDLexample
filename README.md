# SDLexample

[![CMake](https://github.com/ngagesdk/SDLexample/actions/workflows/cmake.yml/badge.svg)](https://github.com/ngagesdk/SDLexample/actions/workflows/cmake.yml)
[![Codacy Badge](https://app.codacy.com/project/badge/Grade/ed8f1a506c6b49e0aafdf291f8d8b030)](https://www.codacy.com/gh/ngagesdk/SDLexample/dashboard?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=ngagesdk/SDLexample&amp;utm_campaign=Badge_Grade)

A simple platform independent [SDL2](https://github.com/libsdl-org/SDL)
sample/base project with a focus on development for the Nokia N-Gage.

## Compiling

The configuration must be adjusted individually for each project. These
settings are located in the file
[project_config.cmake](cmake/project_config.cmake).

### Windows

The easiest way to get SDLexample up and running is Visual Studio 2022
with [C++ CMake tools for
Windows](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio)
installed.  Simply open the cloned repository via `File -> Open ->
Folder`.  Everything else is set up automatically and all required
dependencies are fetched at compile time.

### Nokia N-Gage

The procedure for the Nokia N-Gage is the same as for Windows.  You only
need to install and set up the [N-Gage
SDK.](https://github.com/ngagesdk/ngage-toolchain) in advance and select
the respective build configuration in Visual Studio.

Please note: In order for the SDL executable to be executed properly by
the launcher, the path in the file
[ngage_appui.cpp](src/ngage_appui.cpp#L35) file must be adjusted
accordingly.  Unfortunately, I have not yet found a way to configure
this dynamically.

In addition to the project configuration, the application launcher also
needs to be customised.  The associated files are located in the
sub-folder [res](res/).

### Linux

SDLexample can also be compiled on Linux with the included CMake
configuration.

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
