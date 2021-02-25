## Usage

To install c-make, linux

```
https://vitux.com/how-to-install-cmake-on-ubuntu-18-04/
```

Compile an existing build
--

while you are at the ./< Name of the folder you stored the repo>/cmake-build-debug compile using

```
cmake --build .
```

New build
--

To make a new build, create a folder with the desired name and cd in to that folder and  run CMake to configure the project and generate a native build system:
```
mkdir <folder name>

cd <folder name>

cmake ../<exec name>
```

Finally to run, while you are in the build folder
```
./<exec name> arg1 arg2 ..
```