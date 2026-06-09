#include <iostream>
#include <chrono>

int matrix[10000][10000]{0};

int main()
{
    // =====================================================
    // 1. Row-Major (Fast: sequential memory access)
    // =====================================================
    auto start_row = std::chrono::high_resolution_clock::now();

    for (int row = 0; row < 10000; row++) {
        for (int column = 0; column < 10000; column++) {
            matrix[row][column] += 1; 
        }
    }

    auto end_row = std::chrono::high_resolution_clock::now();
    auto duration_row_major = std::chrono::duration_cast<std::chrono::microseconds>(end_row - start_row);
    std::cout << "Row-Major:    Execution time: " << duration_row_major.count() << " microseconds\n";

    // =====================================================
    // 2. Column-Major (Slow: jumping across memory strides)
    // =====================================================
    auto start_col = std::chrono::high_resolution_clock::now();

    for (int column = 0; column < 10000; column++) {
        for (int row = 0; row < 10000; row++) {
            matrix[row][column] += 1; // Jumping down rows within the same column
        }
    }

    auto end_col = std::chrono::high_resolution_clock::now();
    auto duration_column_major = std::chrono::duration_cast<std::chrono::microseconds>(end_col - start_col);
    std::cout << "Column-Major: Execution time: " << duration_column_major.count() << " microseconds\n";

    return 0;
}
