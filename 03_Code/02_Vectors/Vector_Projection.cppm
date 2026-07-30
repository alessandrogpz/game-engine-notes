// Related Concept: [[01_Concepts/02_Vectors/06_Vector_Projection|06_Vector_Projection]]
export module vectors_projection;

import vectors_basics;
import vectors_dot_product;
import linear_algebra_util;


export namespace vectors {

    [[nodiscard]]
    float scalarProj ( const vector3 a, const vector3 b ) {

        const float magB = magnitude(b);
        if (util::floatEqual(magB, 0.0f))
            return 0.0f;

        return dot(a, b) / magB;
    }

    [[nodiscard]]
    vector3 vecProj ( const vector3 a, const vector3 b ) {
        const float magB = magnitude(b);
        if (util::floatEqual(magB, 0.0f))
            return {0.0f, 0.0f, 0.0f};

        const float sProj = scalarProj(a, b);
        return b * (sProj / magB);
    }

    [[nodiscard]]
    vector3 vecRej ( const vector3 a, const vector3 b) {
        return a - vecProj(a, b);
    }


}
