cmake_minimum_required(VERSION 3.8)
project(Boid_algorithm_TBB)

set(CMAKE_CXX_STANDARD 11)
find_package(glfw3 3.2.1 REQUIRED)
find_package (OpenGL REQUIRED)
find_package(PkgConfig REQUIRED)
include_directories(${GLFW_INCLUDE_DIRS})
set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS} -L/usr/local/lib -framework Cocoa -framework IOKit -framework OpenCL -framework CoreVideo -lglfw3")

set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/local/lib)
link_directories(/usr/local/lib)


list(APPEND CMAKE_MODULE_PATH "/Users/Np/Documents/FindTBB-master")
find_package(TBB COMPONENTS tbbmalloc tbbmalloc_proxy tbb_preview)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS}  -framework OpenGL")

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})


set(SOURCE_FILES main.cpp Engine.cpp Engine.h Flock.cpp Flock.h Boid.cpp Boid.h Draw.cpp Draw.h)
add_executable(Boid_algorithm_TBB ${SOURCE_FILES})



target_link_libraries(Boid_algorithm_TBB tbb)
