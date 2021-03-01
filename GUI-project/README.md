# Qt GUI Project

## Configure
Dowmload the libaray Qt: <https://download.qt.io/official_releases/qt/5.12/5.12.10/>  
[***qt-opensource-windows-x86-5.12.10.exe***](https://download.qt.io/official_releases/qt/5.12/5.12.10/qt-opensource-windows-x86-5.12.10.exe)	for Windows  
[***qt-opensource-linux-x64-5.12.10.run***](https://download.qt.io/official_releases/qt/5.12/5.12.10/qt-opensource-linux-x64-5.12.10.run) for Linux  
[***qt-opensource-mac-x64-5.12.10.dmg***](https://download.qt.io/official_releases/qt/5.12/5.12.10/qt-opensource-mac-x64-5.12.10.dmg) for Mac OS  
(It requres an account during installing. If you don't want to create one, you can disconnect the Internet to skip the registration before executing the install package)

## Build in IDE
The project file called `<project name>.pro`.  
If there is a file `<project name>.pro.user` which records the user's infos (normally, this file is in the *.gitignore*, just in case), it is necessary to delet this file before opening the project. If not, IDE will find that this project is being opening by an other user, and refuse to open or build.

## Build in command line
### -- For Linux / Max OS
1. Find the path of the executable file *qmake*
2. Move to the project directory  
  `cd ...`
3. if *.pro file does not exist:   
  - `<path>/qmake -project` to create the project file.  
  - Add the *lib*s to the project file, such as `QT += network Core`, `QT -= gui`, etc.  
  ref : <https://doc.qt.io/qt-5/qmake-manual.html>  
  ref : <https://doc.qt.io/qt-5/qmake-project-files.html>
4. `<path>/qmake -makefile` to produce Makefile
5. Run the Makefile : `make clean && make `

### -- For Windows (MinGw)
1. Step 1 to 4 are the same as Linux / Mac OS
2. Get the **Debug** version : `mingw32-make -f Makefile.Debug`  
   Get the **Release** version : `mingw32-make -f Makefile.Release`

### -- For Windows (General)
1. Step 1 to 4 are the same as Linux / Mac OS
2. `nmake Debug Release`  
**Notice**: If the command `nmake` is not found, you should add the path of `nmake` to environment variable PATH  
If you use VS Code, the path will be   
`<Disk>:\Program Files\Microsoft Visual Studio <version>\VC\bin\`  
Then, in the ***CMD***, run   
`<Disk>:\Program Files\Microsoft Visual Studio <version>\VC\bin\vcvarsall.bat`.  
Finally, re-run the `nmake ...`