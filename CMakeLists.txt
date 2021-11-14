cmake_minimum_required(VERSION 3.1)

project(Chess)

add_executable(${PROJECT_NAME} 
    src/Chess.cpp 
    src/Game.cpp 
    src/Pawn.cpp 
    src/Piece.cpp 
    src/PieceInfo.cpp 
    src/Renderer.cpp
    src/Smart.cpp
)
add_subdirectory(dependencies/SFML)

target_link_directories(${PROJECT_NAME} PUBLIC dependencies/SFML/lib)
target_include_directories(${PROJECT_NAME} 
    PUBLIC include
    PUBLIC dependencies/SFML/include
    )
target_link_libraries(${PROJECT_NAME} sfml-window sfml-system sfml-graphics)
