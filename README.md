# gitpod_cpp_template
Trying to get C++ project running in gitpod with the right configurations etc. 

[![Gitpod
ready-to-code](https://img.shields.io/badge/Gitpod-ready--to--code-blue?logo=gitpod)](https://gitpod.io/#https://github.com/mfouesneau/gitpod_cpp_template/tree/matplotplusplus)

Gitpod is a nice online IDE very similar to VSCode but using Eclipse Theia (https://theia-ide.org/).
In particular it allows pair-coding while still being able to compile and run codes.

This repository holds a basic workspace to start a C++ project and being able to work with gitpod (also vscode).

It configures `conan` (conan.io, the C/C++ Package Manager) to be used with CMake (https://cmake.org/).

The example codes are basic
```c++
#include <iostream>
namespace example {
	void example1(){
	    std::cout << "Example 1 called. \n";
	}
};
```
But also show how to install and use external libraries with conan. I give the example of `xtensor` (https://github.com/xtensor-stack/xtensor)

```c++
#include <iostream>
#include "xtensor/xarray.hpp"
#include "xtensor/xio.hpp"
#include "xtensor/xview.hpp"
#include "example.hpp"

int main() {
    xt::xarray<double> arr1
    {{1.0, 2.0, 3.0},
    {2.0, 5.0, 7.0},
    {2.0, 5.0, 7.0}};

    xt::xarray<double> arr2
    {5.0, 6.0, 7.0};

    xt::xarray<double> res = xt::view(arr1, 1) + arr2;

    std::cout << res;
}
```

Some notes
  * :warning: clangd extension seems to mess up with the compilation options to find dependencies. 
  * I also put the .vscode equivalent so it can be tested offline (works also with vscodium)


## Using conan

requires to install it. I use python installation 

```pip install conan```

You may have to look for the library you need, e.g:
```
conan search xtensor -r conan-center
Existing package recipes:

xtensor/0.21.2
xtensor/0.21.3
xtensor/0.21.4
xtensor/0.21.5
```

add your requirements to the `conanfile.txt`, e.g, 
```yaml
[requires]
 xtensor/0.21.5

[generators]
 cmake
 ```
(don't forget the generators section)

Update your `CMakeLists.txt` to include the conan libraries, for instance before the targets
```cmake
include(conanbuildinfo.cmake)
conan_basic_setup()
```
And for the relevant targets
```cmake
target_link_libraries(example ${CONAN_LIBS})
```

Finally you will need to run `conan install` before `cmake`
