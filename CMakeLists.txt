cmake_minimum_required(VERSION 3.25.0)

project("Gamefynx" VERSION 1.0.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake/modules)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/inc/ 
    ${CMAKE_SOURCE_DIR}/Core/inc/
    ${CMAKE_SOURCE_DIR}/lib/imgui/
)

#Liste des fichiers
file(GLOB HEADER_FILES ${CMAKE_SOURCE_DIR}/inc/*.h)
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

file(GLOB CORE_HEADER_FILES ${CMAKE_SOURCE_DIR}/Core/inc/*.h)
file(GLOB CORE_SRC_FILES ${CMAKE_SOURCE_DIR}/Core/src/*.cpp)

file(GLOB IMGUI_FILES ${CMAKE_SOURCE_DIR}/lib/imgui/*.cpp)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)


#Exec
add_executable("${PROJECT_NAME}" ${CMAKE_SOURCE_DIR} ${SRC_FILES} ${CORE_SRC_FILES} ${CORE_HEADER_FILES} ${HEADER_FILES} ${IMGUI_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE OpenGL::GL glfw) 





