cmake_minimum_required(VERSION 3.28)
set(CMAKE_SUPPRESS_DEVELOPER_WARNINGS ON CACHE INTERNAL "Suppress dev warnings" FORCE)

# `import std;` is still an experimental CMake feature, gated behind an
# activation UUID that changes with EVERY CMake release. A stale value is
# silently ignored and only surfaces later as an unhelpful "requires toolchain
# support" error at generate time, so the value is tracked here per version and
# verified below.
#
# When a newer CMake is not in this table, look up its value in
# Help/dev/experimental.rst in that version's source tree, then either add it
# here or pass -DLA_IMPORT_STD_UUID=<uuid> on the command line.
if(NOT DEFINED LA_IMPORT_STD_UUID)
    if(CMAKE_VERSION VERSION_GREATER_EQUAL "4.4.0")
        set(LA_IMPORT_STD_UUID "f35a9ac6-8463-4d38-8eec-5d6008153e7d")
    elseif(CMAKE_VERSION VERSION_GREATER_EQUAL "4.3.0")
        set(LA_IMPORT_STD_UUID "451f2fe2-a8a2-47c3-bc32-94786d8fc91b")
    else()
        set(LA_IMPORT_STD_UUID "d0edc3af-4c50-42ea-a356-e2862fe7a444")
    endif()
endif()
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "${LA_IMPORT_STD_UUID}")

project(LinearAlgebra C CXX)

# Fail here, with an actionable message, rather than at generate time.
if(NOT CMAKE_CXX_COMPILER_IMPORT_STD)
    message(FATAL_ERROR
        "`import std;` support was not enabled for CMake ${CMAKE_VERSION}.\n"
        "Reason: ${CMAKE_CXX_COMPILER_IMPORT_STD_ERROR_MESSAGE}\n"
        "The activation UUID tried was ${LA_IMPORT_STD_UUID}, which this CMake "
        "does not accept. Find the correct value for this release in "
        "Help/dev/experimental.rst of its source tree and reconfigure with "
        "-DLA_IMPORT_STD_UUID=<uuid>.")
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_MODULE_STD ON)

# Define static library for linear algebra modules
add_library(LinearAlgebraLib STATIC)

# Define target C++ module interface files (.cppm) on the library target
target_sources(LinearAlgebraLib
  PUBLIC
    FILE_SET CXX_MODULES FILES
        "linear_algebra.cppm"
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
    target_compile_options(LinearAlgebraLib PRIVATE /W4)
else()
    target_compile_options(LinearAlgebraLib PRIVATE -Wall -Wextra -Wpedantic -mavx)
endif()

# Define main application executable linking to our library
add_executable(LinearAlgebra main.cpp)
target_link_libraries(LinearAlgebra PRIVATE LinearAlgebraLib)

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
