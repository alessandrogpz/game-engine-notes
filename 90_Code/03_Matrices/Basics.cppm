// Related Concept: [01_Basics](../../01_Mathematics/01_Linear_Algebra/Concepts/03_Matrices/01_Basics.md)
module;

#include <cstddef>
#include <iomanip>
#include <ios>
#include <iostream>

export module matrices_basics;

export namespace matrices {
    struct Matrix4x4
    {
        float data[16];

        Matrix4x4() : data{} {}

        [[nodiscard]]
        float& operator[](const std::size_t row, const std::size_t col) {
            return data[ row * 4 + col ];
        }

        [[nodiscard]]
        const float& operator[](const std::size_t row, const std::size_t col) const {
            return data[ row * 4 + col ];
        }

        // 1. Matrix Addition
        [[nodiscard]]
        Matrix4x4 operator+(const Matrix4x4& other) const {
            Matrix4x4 result{};
            for (std::size_t i = 0; i < 16; ++i) {
                result.data[i] = data[i] + other.data[i];
            }
            return result;
        }

        // 2. Matrix Subtraction
        [[nodiscard]]
        Matrix4x4 operator-(const Matrix4x4& other) const {
            Matrix4x4 result{};
            for (std::size_t i = 0; i < 16; ++i) {
                result.data[i] = data[i] - other.data[i];
            }
            return result;
        }

        // 3. Scalar Multiplication
        [[nodiscard]]
        Matrix4x4 operator*(const float scalar) const {
            Matrix4x4 result{};
            for (std::size_t i = 0; i < 16; ++i) {
                result.data[i] = data[i] * scalar;
            }
            return result;
        }

        // 5. Trace of a Matrix (Sum of main diagonal elements)
        [[nodiscard]]
        float trace() const {
            return data[0] + data[5] + data[10] + data[15];
        }

        // 6. Identity Matrix
        static Matrix4x4 identity()
        {
            Matrix4x4 i{};
            i[0, 0] = 1.0;
            i[1, 1] = 1.0;
            i[2, 2] = 1.0;
            i[3, 3] = 1.0;
            return i;
        }
    };

    // 4. Matrix Transposition
    [[nodiscard]]
    Matrix4x4 transpose(const Matrix4x4& m)
    {
        Matrix4x4 t{};
        for ( int row = 0; row < 4; row++ )
        {
            for ( int column = 0; column < 4; column++ )
            {
                t[column, row] = m[row, column];
            }
        }
        return t;
    }

    // 7. 4x4 ASCII Matrix Printer
    void print(const Matrix4x4& m)
    {
        // setw/setprecision are sticky on the stream, so the caller's
        // formatting is saved and restored around the printout.
        const std::ios_base::fmtflags savedFlags = std::cout.flags();
        const std::streamsize savedPrecision = std::cout.precision();
        std::cout << std::fixed << std::setprecision(4);

        for (std::size_t row = 0; row < 4; ++row)
        {
            std::cout << "[ ";
            for (std::size_t col = 0; col < 4; ++col)
            {
                std::cout << std::setw(8) << m[row, col] << ' ';
            }
            std::cout << "]" << std::endl;
        }

        std::cout.flags(savedFlags);
        std::cout.precision(savedPrecision);
    }

    [[nodiscard]]
    float trace(const Matrix4x4& m) {
        return m.trace();
    }
}
