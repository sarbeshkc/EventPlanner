cmake_minimum_required(VERSION 3.14)

project(CampusEventPlanner)

set(CMAKE_CXX_STANDARD 17)

# Set build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Set compiler flags for Release build
if(CMAKE_BUILD_TYPE MATCHES Release)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -DNDEBUG")
endif()

# Find OpenGL
find_package(OpenGL REQUIRED)

# ImGui
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/extern/imgui)
set(IMGUI_INCLUDE_DIR ${IMGUI_DIR} ${IMGUI_DIR}/backends)
file(GLOB IMGUI_SOURCES ${IMGUI_DIR}/*.cpp)
set(IMGUI_IMPL_SOURCES
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
)

# GLFW
set(GLFW_DIR ${CMAKE_SOURCE_DIR}/extern/glfw)
add_subdirectory(${GLFW_DIR})

# SQLite (using FetchContent)
include(FetchContent)
FetchContent_Declare(
    sqlite3
    GIT_REPOSITORY https://github.com/sqlite/sqlite.git
    GIT_TAG version-3.37.2
)
FetchContent_MakeAvailable(sqlite3)


# Boost.ASIO
set(BOOST_ASIO_DIR ${CMAKE_SOURCE_DIR}/extern/boost-asio)
set(BOOST_ASIO_INCLUDE_DIR ${BOOST_ASIO_DIR}/include)


 set(STB_DIR "/home/etoski/Libaries/stb/")

 set (GLAD_DIR "/home/etoski/Personal_Project/EventPlanner/src/object/glad.c")

# Add source files
file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE SOURCES src/*.cpp ${IMGUI_SOURCES} ${IMGUI_IMPL_SOURCES})

# Create the executable
add_executable(CampusEventPlanner ${SOURCES} ${IMGUI_SOURCES} ${IMGUI_IMPL_SOURCES} ${GLAD_DIR})

# Link libraries
target_link_libraries(CampusEventPlanner
    PRIVATE
        glfw
        OpenGL::GL
        sqlite3
)

# Include directories
target_include_directories(CampusEventPlanner
    PRIVATE
        ${CMAKE_SOURCE_DIR}/include
        ${IMGUI_INCLUDE_DIR}
        ${BOOST_ASIO_INCLUDE_DIR}
        ${STB_DIR}
)

add_compile_options(-ggdb)
