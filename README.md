### dirclassifier ###

dirclassifier create a directory tree that represents entries in which symbolic links are used to 
point to other directories and thus classify them. JSON files are used to specify the entries in 
the source directories. For information about how to write them and use the program use
`dirclassifier --help` command.

### Build ###

Use the folowing commands to buil and install the CMake project.

    Create a directory to hold the build output and generate the native build scripts:
            $ cmake -H. -Bbuild

    Compile the project directly from CMake using the native build scripts:
            $ cmake --build build

    Install the binary in your environment:
            $ sudo cmake --install build

#### Dependencies ####

In order to compile this software you have to use a C++ revision equal or highter to C++17 
(ISO/IEC 14882:2017). Also the following tools and libraries are necessary with a version equal or 
highter the specified one:
- GCC 8.3.0 (sudo apt-get install g++)
- CMake 3.15 (http://www.cmake.org/)
- speed (https://github.com/killianValverde/speed)
- boost 1.58 (sudo apt-get install libboost-dev)
