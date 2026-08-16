# GoogleTest integration
include(GoogleTest)

# Define test executable containing all unit test files
add_executable(EngineNotesTests
    Systems_of_Equations/Linear_Systems_tests.cpp
    Vectors/Basics_tests.cpp
    Vectors/Coordinate_Systems_tests.cpp
    Vectors/Dot_Product_tests.cpp
    Vectors/Cross_Product_tests.cpp
    Vectors/Vector_Projection_tests.cpp
    Matrices/Basics_tests.cpp
    Matrices/Multiplication_tests.cpp
    Matrices/Determinants_tests.cpp
    Matrices/Inversion_tests.cpp
    Matrices/Orthogonal_tests.cpp
    Matrices/Projection_tests.cpp
    Transforms/Rotations_tests.cpp
    Transforms/Scales_tests.cpp
    Transforms/Reflections_tests.cpp
    Transforms/Skews_tests.cpp
    Transforms/Translations_tests.cpp
    Transforms/Quaternions_tests.cpp
    Geometry/Triangle_Meshes_tests.cpp
    Geometry/Normal_Vectors_tests.cpp
)

# Set standards and modules
target_compile_features(EngineNotesTests PRIVATE cxx_std_23)

# Compiler options
if(MSVC)
    target_compile_options(EngineNotesTests PRIVATE /W4)
else()
    target_compile_options(EngineNotesTests PRIVATE -Wall -Wextra -Wpedantic -mavx)
endif()

# Link with our C++ module library and GoogleTest
target_link_libraries(EngineNotesTests
    PRIVATE
        EngineNotesLib
        GTest::gtest_main
)

# Discover tests automatically
gtest_discover_tests(EngineNotesTests)
