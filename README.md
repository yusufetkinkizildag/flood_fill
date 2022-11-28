# flood_fill
My iterative implementation of flood fill algorithm using stack and queue in c++17. Actually they only differ in only one line. The stack calls the `top()` function and the queue calls the `front()` function to get the next index pair. The rest is the same.

## Requirements
gcc 9.4.0

More info on [compiler](#compiler)

## Useful Links
[link1](https://www.educative.io/answers/flood-fill-algorithm-in-cpp), [link2](https://www.geeksforgeeks.org/flood-fill-algorithm-implement-fill-paint/)

## How to compile
```console
cd /path/to/flood_fill
bash clean_build.sh
```

## How to run
```console
cd /path/to/flood_fill
./build/flood_fill
```

## clean_build.sh
A trivial shell script that checks and deletes if `build` folder exists.
Calls the cmake and make to build and compile the source code

## CMakeLists.txt
A basic cmake file to specify C and C++ standards, build type and compile options.

## Compiler
I'm using docker desktop on MacOS Ventura 13.0. So the `g++` on the system outputs the following lines.

```zsh
g++ -v
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: arm64-apple-darwin22.1.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```
Inside the docker
```bash
root@33f028642cdf:/# g++ -v
Using built-in specs.
COLLECT_GCC=g++
COLLECT_LTO_WRAPPER=/usr/lib/gcc/aarch64-linux-gnu/9/lto-wrapper
Target: aarch64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=aarch64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-libquadmath --disable-libquadmath-support --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --enable-fix-cortex-a53-843419 --disable-werror --enable-checking=release --build=aarch64-linux-gnu --host=aarch64-linux-gnu --target=aarch64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
```
The gcc outputs the following lines

```zsh
gcc -v
Apple clang version 14.0.0 (clang-1400.0.29.202)
Target: arm64-apple-darwin22.1.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```

Inside the docker

```bash
root@33f028642cdf:/# gcc -v
Using built-in specs.
COLLECT_GCC=gcc
COLLECT_LTO_WRAPPER=/usr/lib/gcc/aarch64-linux-gnu/9/lto-wrapper
Target: aarch64-linux-gnu
Configured with: ../src/configure -v --with-pkgversion='Ubuntu 9.4.0-1ubuntu1~20.04.1' --with-bugurl=file:///usr/share/doc/gcc-9/README.Bugs --enable-languages=c,ada,c++,go,d,fortran,objc,obj-c++,gm2 --prefix=/usr --with-gcc-major-version-only --program-suffix=-9 --program-prefix=aarch64-linux-gnu- --enable-shared --enable-linker-build-id --libexecdir=/usr/lib --without-included-gettext --enable-threads=posix --libdir=/usr/lib --enable-nls --enable-clocale=gnu --enable-libstdcxx-debug --enable-libstdcxx-time=yes --with-default-libstdcxx-abi=new --enable-gnu-unique-object --disable-libquadmath --disable-libquadmath-support --enable-plugin --enable-default-pie --with-system-zlib --with-target-system-zlib=auto --enable-objc-gc=auto --enable-multiarch --enable-fix-cortex-a53-843419 --disable-werror --enable-checking=release --build=aarch64-linux-gnu --host=aarch64-linux-gnu --target=aarch64-linux-gnu
Thread model: posix
gcc version 9.4.0 (Ubuntu 9.4.0-1ubuntu1~20.04.1)
```
