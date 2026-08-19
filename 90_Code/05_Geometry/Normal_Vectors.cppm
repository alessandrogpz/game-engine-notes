// Related Concept: [02_Normal_Vectors](../../01_Mathematics/01_Linear_Algebra/Concepts/05_Geometry/02_Normal_Vectors.md)
module;

export module geometry_normal_vectors;

import matrices_basics;
import vectors_basics;
import matrices_inversion;
import matrices_determinants;
import vectors_cross_product;

export namespace geometry {

    // Face normal of the triangle P0 P1 P2. Winding order decides the
    // direction: swapping any two vertices negates the result, because the
    // cross product is anti-commutative.
    //
    // Not normalized - its length is twice the triangle's area, which callers
    // sometimes want. Use vectors::normalized() when a unit normal is needed.
    [[nodiscard]]
    vectors::vector3 faceNormal(const vectors::vector3 p0,
                                const vectors::vector3 p1,
                                const vectors::vector3 p2)
    {
        return vectors::crossProd((p1 - p0), (p2 - p0));
    }

    // Transforms a normal by M, preserving orthogonality to the surface.
    //
    // A normal does not transform by M itself: under a non-uniform scale or a
    // skew, M n stops being perpendicular to the transformed surface. The
    // inverse-transpose fixes that - scaling x by 2 scales the normal's x by
    // 1/2. For a rotation the two agree, since (M^-1)^T == M when M is
    // orthogonal, so this one function covers every case.
    //
    // The sign of the determinant handles reflection. A reflection mirrors
    // every component, leaving (M^-1)^T n pointing into the surface rather
    // than out of it; det(M) is negative exactly then, so multiplying by its
    // sign flips the result back.
    //
    // The result is re-normalized, since neither scaling nor skewing preserves
    // length.
    [[nodiscard]]
    vectors::vector3 transformNormal(const matrices::Matrix4x4& m,
                                     const vectors::vector3 n)
    {
        const float det = matrices::determinant(m);
        const float sign = (det < 0.0f) ? -1.0f : 1.0f;

        const matrices::Matrix4x4 inverseTranspose =
            matrices::transpose(matrices::inverse(m));

        const vectors::vector3 transformed =
            vectors::transformDirection(inverseTranspose, n);

        return vectors::normalized(transformed * sign);
    }
}
