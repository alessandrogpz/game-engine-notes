// Related Concept: [04_Cross_Product](../../01_Mathematics/01_Linear_Algebra/Concepts/02_Vectors/04_Cross_Product.md)
export module vectors_cross_product;

import vectors_basics;

export namespace vectors {

    [[nodiscard]]
    vector3 crossProd (const vector3 a, const vector3 b) {

        return { (a.y * b.z) - (a.z * b.y),
                    (a.z * b.x) - (a.x * b.z),
                    (a.x * b.y) - (a.y * b.x) };
    }
}
