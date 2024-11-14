cmake_minimum_required(VERSION 3.1)
project(myNES)

# add sources
file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/*.cpp"
    #"${PROJECT_SOURCE_DIR}/Log.cpp"
)

# specify the include dir
include_directories("${PROJECT_SOURCE_DIR}/include")

add_executable(${PROJECT_NAME} ${SOURCES})

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)

target_link_libraries(${PROJECT_NAME})