cmake_minimum_required(VERSION 3.1)

project(Chess)

file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} 
    ${SOURCES}
)

add_subdirectory(dependencies/SFML)
target_link_directories(${PROJECT_NAME} PUBLIC dependencies/SFML/lib)
target_include_directories(${PROJECT_NAME} 
PUBLIC include
PUBLIC dependencies/SFML/include
)

target_link_libraries(${PROJECT_NAME} sfml-system sfml-graphics sfml-window)

add_custom_command(TARGET Chess POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                       ${CMAKE_CURRENT_SOURCE_DIR}/Assets
                       $<TARGET_FILE_DIR:Chess>/Assets
)