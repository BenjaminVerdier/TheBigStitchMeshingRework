cmake_minimum_required(VERSION 3.1)
project(TheBigStitchMeshingRework)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# libigl
option(LIBIGL_WITH_OPENGL            "Use OpenGL"         ON)
option(LIBIGL_WITH_OPENGL_GLFW       "Use GLFW"           ON)

find_package(LIBIGL REQUIRED QUIET)

#gurobi
if (APPLE)
	include_directories("/Library/gurobi911/mac64/include") 
	link_directories("/Library/gurobi911/mac64	/lib")
else ()
	include_directories("C:/gurobi911/win64/include")
	link_directories("C:/gurobi911/win64/lib")
endif()

# Add your project files
file(GLOB SRCFILES *.cpp)
add_executable(${PROJECT_NAME} ${SRCFILES})

if (APPLE)
	target_link_libraries(${PROJECT_NAME} igl::core igl::opengl_glfw libgurobi_c++.a)
else ()
	target_link_libraries(${PROJECT_NAME} igl::core igl::opengl_glfw gurobi91 gurobi_c++mt2019 gurobi_c++mtd2019)
endif()