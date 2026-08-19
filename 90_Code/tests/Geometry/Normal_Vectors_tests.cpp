#include <gtest/gtest.h>
#include <cmath>

import geometry_normal_vectors;
import matrices_basics;
import vectors_basics;
import vectors_dot_product;

TEST(GeometryNormalVectors, FaceNormalOfTriangleInXYPlane) {
    // Counter-clockwise seen from +z, so the normal points along +z.
    const vectors::vector3 n = geometry::faceNormal({0, 0, 0}, {1, 0, 0}, {0, 1, 0});

    EXPECT_FLOAT_EQ(n.x, 0.0);
    EXPECT_FLOAT_EQ(n.y, 0.0);
    EXPECT_FLOAT_EQ(n.z, 1.0);
}

// The cross product is anti-commutative, so reversing the winding flips the
// normal. This is what backface culling depends on.
TEST(GeometryNormalVectors, ReversedWindingNegatesTheNormal) {
    const vectors::vector3 ccw = geometry::faceNormal({0, 0, 0}, {1, 0, 0}, {0, 1, 0});
    const vectors::vector3 cw  = geometry::faceNormal({0, 0, 0}, {0, 1, 0}, {1, 0, 0});

    EXPECT_FLOAT_EQ(cw.x, -ccw.x);
    EXPECT_FLOAT_EQ(cw.y, -ccw.y);
    EXPECT_FLOAT_EQ(cw.z, -ccw.z);
}

// Length is twice the triangle's area: this one has area 1/2.
TEST(GeometryNormalVectors, FaceNormalLengthIsTwiceTheArea) {
    const vectors::vector3 n = geometry::faceNormal({0, 0, 0}, {1, 0, 0}, {0, 1, 0});
    EXPECT_FLOAT_EQ(vectors::magnitude(n), 1.0);
}

TEST(GeometryNormalVectors, IdentityLeavesANormalUnchanged) {
    const matrices::Matrix4x4 i = matrices::Matrix4x4::identity();
    const vectors::vector3 n = geometry::transformNormal(i, {0, 0, 1});

    EXPECT_FLOAT_EQ(n.x, 0.0);
    EXPECT_FLOAT_EQ(n.y, 0.0);
    EXPECT_FLOAT_EQ(n.z, 1.0);
}

// The property that defines a correct normal transform: it stays perpendicular
// to the surface. Take a surface direction, transform both, and the dot product
// must remain zero. Naively using M instead of the inverse-transpose fails this.
TEST(GeometryNormalVectors, StaysOrthogonalUnderNonUniformScale) {
    matrices::Matrix4x4 s = matrices::Matrix4x4::identity();
    s[0, 0] = 2.0;   // scale x by 2

    const vectors::vector3 normal{1, 1, 0};    // surface x + y = 0
    const vectors::vector3 tangent{1, -1, 0};  // a direction lying in it

    const vectors::vector3 newNormal  = geometry::transformNormal(s, normal);
    const vectors::vector3 newTangent = vectors::transformDirection(s, tangent);

    EXPECT_NEAR(vectors::dot(newNormal, newTangent), 0.0, 1e-6);

    // And the naive M n would NOT be orthogonal, which is the whole point.
    const vectors::vector3 naive = vectors::transformDirection(s, normal);
    EXPECT_GT(std::abs(vectors::dot(naive, newTangent)), 1.0);
}

// For an orthogonal matrix the inverse-transpose equals the matrix itself, so
// a rotation transforms a normal exactly as it transforms a direction.
TEST(GeometryNormalVectors, RotationAgreesWithDirectTransform) {
    const float c = std::cos(1.0f), sn = std::sin(1.0f);
    matrices::Matrix4x4 r = matrices::Matrix4x4::identity();
    r[0, 0] =  c; r[0, 1] = -sn;
    r[1, 0] = sn; r[1, 1] =  c;

    const vectors::vector3 n{0, 0, 1};
    const vectors::vector3 viaNormal = geometry::transformNormal(r, n);
    const vectors::vector3 viaDirect = vectors::normalized(vectors::transformDirection(r, n));

    EXPECT_NEAR(viaNormal.x, viaDirect.x, 1e-6);
    EXPECT_NEAR(viaNormal.y, viaDirect.y, 1e-6);
    EXPECT_NEAR(viaNormal.z, viaDirect.z, 1e-6);
}

// A reflection has det < 0. Without the sign correction the normal would come
// back pointing into the surface instead of out of it.
TEST(GeometryNormalVectors, ReflectionKeepsTheNormalPointingOutward) {
    matrices::Matrix4x4 reflectX = matrices::Matrix4x4::identity();
    reflectX[0, 0] = -1.0;

    const vectors::vector3 n = geometry::transformNormal(reflectX, {1, 0, 0});

    // sign(det) = -1 cancels the mirror, so it stays on +x.
    EXPECT_FLOAT_EQ(n.x, 1.0);
    EXPECT_FLOAT_EQ(n.y, 0.0);
    EXPECT_FLOAT_EQ(n.z, 0.0);
}

// Scaling and skewing do not preserve length, so the result is re-normalized.
TEST(GeometryNormalVectors, ResultIsAlwaysUnitLength) {
    matrices::Matrix4x4 s = matrices::Matrix4x4::identity();
    s[0, 0] = 5.0; s[1, 1] = 0.25; s[2, 2] = 3.0;

    const vectors::vector3 n = geometry::transformNormal(s, {1, 2, 3});
    EXPECT_NEAR(vectors::magnitude(n), 1.0, 1e-6);
}
