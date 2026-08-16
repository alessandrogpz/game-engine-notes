#include <gtest/gtest.h>

import matrices_basics;
import matrices_projection;
import vectors_basics;
import vectors_dot_product;

TEST(MatricesProjection, ProjectionOntoAxisKeepsParallelComponent) {
    // Projecting onto the X axis keeps x and discards y and z.
    matrices::Matrix4x4 P = matrices::projMatrix(vectors::vector3(3.0f, 0.0f, 0.0f));
    vectors::vector3 v(2.0f, 5.0f, -7.0f);

    vectors::vector3 p = matrices::vecProj(P, v);
    EXPECT_NEAR(p.x, 2.0f, 1e-5f);
    EXPECT_NEAR(p.y, 0.0f, 1e-5f);
    EXPECT_NEAR(p.z, 0.0f, 1e-5f);
}

TEST(MatricesProjection, RejectionMatrixIsAffine) {
    // identity() - projMatrix() subtracts 1 from the homogeneous slot as well,
    // which used to leave R[3, 3] = 0 and break composition with other 4x4
    // transforms.
    matrices::Matrix4x4 R = matrices::orthogonalRejMatrix(vectors::vector3(0.0f, 1.0f, 0.0f));

    EXPECT_FLOAT_EQ((R[3, 3]), 1.0f);
    EXPECT_FLOAT_EQ((R[3, 0]), 0.0f);
    EXPECT_FLOAT_EQ((R[3, 1]), 0.0f);
    EXPECT_FLOAT_EQ((R[3, 2]), 0.0f);
}

TEST(MatricesProjection, ProjectionPlusRejectionReconstructsVector) {
    const vectors::vector3 axis(1.0f, 2.0f, 3.0f);
    const vectors::vector3 v(4.0f, -1.0f, 2.0f);

    const vectors::vector3 p = matrices::vecProj(matrices::projMatrix(axis), v);
    const vectors::vector3 r = matrices::vecRej(matrices::orthogonalRejMatrix(axis), v);

    // The two components must sum back to the original vector...
    EXPECT_NEAR(p.x + r.x, v.x, 1e-5f);
    EXPECT_NEAR(p.y + r.y, v.y, 1e-5f);
    EXPECT_NEAR(p.z + r.z, v.z, 1e-5f);

    // ...and the rejection must be orthogonal to the axis.
    EXPECT_NEAR(vectors::dot(r, axis), 0.0f, 1e-5f);
}
