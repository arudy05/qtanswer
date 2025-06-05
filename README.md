# QtAnswer
A work-in-progress Jeopardy-like trivia game using the Qt toolkit. 

## Building
### Requirements
- Qt 6.9.0 (other versions may or may not work since this is a relatively simple application, try it out at your own risk)
- CMake 3.16 or higher
### Instructions
Simply run the following: 
```
git clone https://github.com/arudy05/qtanswer.git
cd qtanswer
mkdir build && cd build
cmake ..
cmake --build .
```
The executable can be found at `<REPOSITORY LOCATION>/qtanswer/build/src/qtanswer`.
