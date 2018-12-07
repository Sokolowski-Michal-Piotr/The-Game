cmake_minimum_required(VERSION 3.1)
project(The-Game)

file(GLOB HEADER "${PROJECT_SOURCE_DIR}/source/*.hpp")
file(GLOB SOURCE "${PROJECT_SOURCE_DIR}/source/*.cpp")
source_group("header" FILES ${HEADER})
source_group("source" FILES ${SOURCE})

set(CMAKE_CXX_STANDARD 11)
set(EXECUTABLE_NAME "The-Game")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
add_executable(${EXECUTABLE_NAME} ${SOURCE} ${HEADER})
set_target_properties(${EXECUTABLE_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

set(SFML_DIR ${PROJECT_SOURCE_DIR}/3rdparty/SFML/lib/cmake/SFML/)
find_package(SFML COMPONENTS graphics audio REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} sfml-graphics sfml-audio)
