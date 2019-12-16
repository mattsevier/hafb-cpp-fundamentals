## C++ Environment in Windows
-using VS code for editor https://code.visualstudio.com/
-git //for source control  https://git-scm.com/
-cmake //to work with projects  cmake.org
-g++ (mingw) //compiler for windows.  You need to add binaries to path environment variable 
-add c:\Mingw\bin\ to PATH Environment variable
-mingw32-make //used by cmake
-mingw
 mingw.org
## Terminal Commands
Note $ means terminal prompt
```bash
$ ls # list foled
$ cd <destination> # change directories
$ cd .. #.. parent directory
$ pwd #show present directory
$ rm # remove / delete file/directory
```
## File System
. # (one dot) present working directory
.. #(two dots) parent directory

## C++ Basics
- file extension: `.cpp`

## g++ Compiler
# to compile
# -o for output file name
$ g++ main.cpp -o main
# To run
$ ./main.exe

## C++ File Template
```cpp
#include <iostream>
using namespace std;

int main()
{
    return 0;
}
```
## Doxygen documentation 
```cpp
//add code spell (search spell)
// add c/c++ intellisense
// using plugin doxygen documentation generator
//run at the beginning of the code - /** (ENTER) to generate documentation
```
Markdown all in one plugin
cmake and cmake tools plugins (search cmake, first two)