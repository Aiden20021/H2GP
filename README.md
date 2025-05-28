
## Download file:

https://www.raylib.com/ voor raylib installer

https://winlibs.com/#download-release

(https://github.com/brechtsanders/winlibs_mingw/releases/download/15.1.0posix-12.0.0-ucrt-r1/winlibs-x86_64-posix-seh-gcc-15.1.0-mingw-w64ucrt-12.0.0-r1.zip)

TODO win64 ook keer testen!!!






Installing and building raylib via vcpkg
You can download and install raylib using the vcpkg dependency manager:

```bash
  git clone https://github.com/Microsoft/vcpkg.git
  cd vcpkg
  bootstrap-vcpkg.bat
  vcpkg integrate install
  vcpkg install raylib
```

TODO: Dit ook keer testen
The default triplet in vcpkg is set to "x86-windows". If you want to install x64 version instead, you should use following command:

  vcpkg install raylib:x64-windows






Om een raylib te compilen!!!
Maak bestand aan main.cpp met de raylib example code (alleen een window)
Download raylib 

https://github.com/raysan5/raylib/releases/download/5.5/raylib-5.5_win64_msvc16.zip

Zet die in c:\raylib

Met dit commando kun je dan compilen:

g++ main.cpp -o r -lraylib -lgdi32 -lwinmm -Lc:\raylib\lib -Ic:\raylib\include
