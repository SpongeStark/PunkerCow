# Qt GUI Project

## configure
Dowmload the libaray Qt: <https://download.qt.io/official_releases/qt/5.12/5.12.10/>

### -- For Linux / Max OS
1. Find the executable file *qmake*
2. if *.pro file does noy exist:   
  - `<path>/qmake -project` to create the project file.  
  - Add the *lib*s to the project file, such as `QT += network Core`, `QT -= gui`, etc.  
  ref : <https://doc.qt.io/qt-5/qmake-manual.html>  
  ref : <https://doc.qt.io/qt-5/qmake-project-files.html>
3. `<path>/qmake -makefile` to produce Makefile
4. Run the Makefile : `make clean && make `
