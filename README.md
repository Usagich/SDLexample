# SDLexample

A simple [SDL 2.0.x](https://github.com/libsdl-org/SDL) sample project.

## Compiling

### Windows

The easiest way to get SDLexample up and running is Visual Studio 2022
with [C++ CMake tools for
Windows](https://docs.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio)
installed.  Simply open the cloned repository via `File -> Open ->
Folder`.  Everything else is set up automatically.

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

This project is licensed under the "The MIT License".  See the file
[LICENSE.md](LICENSE.md) for details.
