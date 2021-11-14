cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Minesweeper)


add_executable(${PROJECT_NAME} src/main.cpp src/Button.cpp src/Game.cpp)
link_directories(lib)

target_include_directories(${PROJECT_NAME} PUBLIC include)
target_link_libraries(${PROJECT_NAME} sfml-window sfml-system sfml-graphics)
