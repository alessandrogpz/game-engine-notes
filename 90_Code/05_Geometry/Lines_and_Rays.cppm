// Related Concept: [03_Lines_and_Rays](../../01_Mathematics/01_Linear_Algebra/Concepts/05_Geometry/03_Lines_and_Rays.md)
module;

#include <cmath>

export module geometry_lines_and_rays;

import vectors_basics;
import vectors_dot_product;
import vectors_cross_product;
import engine_util;

export namespace geometry {

    // Shortest distance from the point q to the line L(t) = p + t v.
    [[nodiscard]]
    float distancePointLine(const vectors::vector3 q,   // the query point
                            const vectors::vector3 p,   // a point on the line
                            const vectors::vector3 v)   // the line's direction
    {

        const float vv = vectors::dot(v, v);
        if (vv <= util::EPSILON * util::EPSILON)
            return vectors::magnitude(q - p);

        // Vector from 'p' to 'q'
        const vectors::vector3 u = q - p;

        const vectors::vector3 c = vectors::crossProd(u, v);
        return std::sqrt(vectors::dot(c, c) / vv);
    }

    // Shortest distance between the lines L1(t) = p1 + t v1 and L2(t) = p2 + t v2.
    [[nodiscard]]
    float distanceLineLine( const vectors::vector3 p1,
                            const vectors::vector3 v1,
                            const vectors::vector3 p2,
                            const vectors::vector3 v2)
    {
        const vectors::vector3 n = vectors::crossProd(v1, v2);
        const float nn = vectors::dot(n, n);

        const float scale = vectors::dot(v1, v1) * vectors::dot(v2, v2);
        if (nn <= util::EPSILON * util::EPSILON * scale)
            return distancePointLine(p2, p1, v1);

        const float signedVolume = vectors::dot(p2 - p1, n);

        return std::sqrt((signedVolume * signedVolume) / nn);
    }

}
