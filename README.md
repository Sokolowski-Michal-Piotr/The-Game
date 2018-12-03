### The Game
#### Used technologies:
- C++
- SFML
- CMake
- Bash

#### How to start:
1. Generate the build.
    * CMake:
        * Manual generation requires installing SFML first.
        * Installing SFML is based on CMake aswell.
    * Setup.sh:
        * Should generate the build using default generator.
        * Tested for Visual Studio 2017.
        * Uses various options:
            * a (all) - performs clean, install, generate and copy dll options at once.
            * c (clean) - deletes 3rdparty and build dir.
            * i (install) - installs 3rdparty dependancies.
            * g (generate) - generates the build.
            * d (copy dll) - copies dlls to executable directory.
2. Build.
3. Run.
