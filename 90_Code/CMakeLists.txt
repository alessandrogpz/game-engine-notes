cmake_minimum_required(VERSION 3.28)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON CACHE INTERNAL "Suppress dev warnings" FORCE)

project(EngineNotes C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define static library for linear algebra modules
add_library(EngineNotesLib STATIC)

# Define target C++ module interface files (.cppm) on the library target
target_sources(EngineNotesLib
  PUBLIC
    FILE_SET CXX_MODULES FILES
        "engine_notes.cppm"
        "00_Utils/util.cppm"
        "01_Systems_of_Equations/Linear_Systems.cppm"
        "02_Vectors/Basics.cppm"
        "02_Vectors/Dot_Product.cppm"
        "02_Vectors/Coordinate_Systems.cppm"
        "02_Vectors/Cross_Product.cppm"
        "02_Vectors/Scalar_Triple_Product.cppm"
        "02_Vectors/Vector_Projection.cppm"
        "03_Matrices/Basics.cppm"
        "03_Matrices/Matrix_Multiplication.cppm"
        "03_Matrices/Determinants.cppm"
        "03_Matrices/Matrix_Inversion.cppm"
        "03_Matrices/Orthogonal_Matrices.cppm"
        "03_Matrices/Projection_Matrices.cppm"
        "04_Transforms/Rotations.cppm"
        "04_Transforms/Reflections.cppm"
        "04_Transforms/Scales.cppm"
        "04_Transforms/Skews.cppm"
        "04_Transforms/Translations.cppm"
        "04_Transforms/Quaternions.cppm"
        "05_Geometry/Triangle_Meshes.cppm"
        "05_Geometry/Normal_Vectors.cppm"
        "05_Geometry/Lines_and_Rays.cppm"
        "05_Geometry/Planes.cppm"
        "05_Geometry/Distance_Point_and_Plane.cppm"
        "05_Geometry/Reflection_Through_Plane.cppm"
        "05_Geometry/Intersection_Line_and_Plane.cppm"
        "05_Geometry/Intersection_Three_Planes.cppm"
        "05_Geometry/Intersection_Two_Planes.cppm"
        "05_Geometry/Transforming_Planes.cppm"
)

# Set compile flags on the library target
if(MSVC)
    target_compile_options(EngineNotesLib PRIVATE /W4)
else()
    target_compile_options(EngineNotesLib PRIVATE -Wall -Wextra -Wpedantic -mavx)
endif()

# Define main application executable linking to our library
add_executable(EngineNotes main.cpp)
target_link_libraries(EngineNotes PRIVATE EngineNotesLib)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.15.2
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing and add tests subdirectory
enable_testing()
add_subdirectory(tests)
