#include <gtest/gtest.h>
#include <cmath>

import geometry_lines_and_rays;
import vectors_basics;

// --- distancePointLine -----------------------------------------------------

TEST(GeometryLinesAndRays, PointOffTheXAxis) {
    // (0,3,4) against the x-axis: distance is the yz magnitude, 5.
    EXPECT_FLOAT_EQ(geometry::distancePointLine({0, 3, 4}, {0, 0, 0}, {1, 0, 0}), 5.0);
}

TEST(GeometryLinesAndRays, PointOnTheLineIsZero) {
    EXPECT_NEAR(geometry::distancePointLine({5, 0, 0}, {0, 0, 0}, {1, 0, 0}), 0.0, 1e-6);
}

// The |v| in numerator and denominator cancel, so the direction's length must
// not change the answer.
TEST(GeometryLinesAndRays, DirectionLengthDoesNotMatter) {
    const float unit    = geometry::distancePointLine({0, 3, 4}, {0, 0, 0}, {1, 0, 0});
    const float scaled  = geometry::distancePointLine({0, 3, 4}, {0, 0, 0}, {7, 0, 0});
    EXPECT_FLOAT_EQ(unit, scaled);
}

TEST(GeometryLinesAndRays, LineNotThroughTheOrigin) {
    // Line x = 1 running along z; the point is 2 away in y.
    EXPECT_FLOAT_EQ(geometry::distancePointLine({1, 2, 3}, {1, 0, 0}, {0, 0, 1}), 2.0);
}

// A zero direction is not a line: it collapses to the point p, and the distance
// to that point is returned rather than a divide-by-zero.
TEST(GeometryLinesAndRays, ZeroDirectionCollapsesToPointDistance) {
    EXPECT_FLOAT_EQ(geometry::distancePointLine({3, 4, 0}, {0, 0, 0}, {0, 0, 0}), 5.0);
}

// --- distanceLineLine ------------------------------------------------------

TEST(GeometryLinesAndRays, SkewLines) {
    // x-axis, and a line along y raised to z = 1. They never meet; gap is 1.
    EXPECT_FLOAT_EQ(geometry::distanceLineLine({0, 0, 0}, {1, 0, 0},
                                               {0, 0, 1}, {0, 1, 0}), 1.0);
}

// The triple product is signed. Putting the second line below rather than above
// must not reach std::sqrt as a negative, which would return NaN.
TEST(GeometryLinesAndRays, ReversedOrderIsStillPositive) {
    const float d = geometry::distanceLineLine({0, 0, 0}, {1, 0, 0},
                                               {0, 0, -1}, {0, 1, 0});
    EXPECT_FALSE(std::isnan(d));
    EXPECT_FLOAT_EQ(d, 1.0);
}

// Both direction lengths appear above and below and cancel.
TEST(GeometryLinesAndRays, ScalingEitherDirectionChangesNothing) {
    const float base = geometry::distanceLineLine({0, 0, 0}, {1, 0, 0}, {0, 0, 1}, {0, 1, 0});
    const float v1x3 = geometry::distanceLineLine({0, 0, 0}, {3, 0, 0}, {0, 0, 1}, {0, 1, 0});
    const float v2x3 = geometry::distanceLineLine({0, 0, 0}, {1, 0, 0}, {0, 0, 1}, {0, 3, 0});
    const float both = geometry::distanceLineLine({0, 0, 0}, {7, 0, 0}, {0, 0, 1}, {0, 7, 0});

    EXPECT_FLOAT_EQ(v1x3, base);
    EXPECT_FLOAT_EQ(v2x3, base);
    EXPECT_FLOAT_EQ(both, base);
}

// Intersecting lines need no special case: the volume is zero.
TEST(GeometryLinesAndRays, IntersectingLinesAreZeroApart) {
    EXPECT_NEAR(geometry::distanceLineLine({0, 0, 0}, {1, 0, 0},
                                           {0, 0, 0}, {0, 1, 0}), 0.0, 1e-6);
}

// Parallel lines have no unique common perpendicular, so the cross product
// vanishes and the point-line route is taken instead.
TEST(GeometryLinesAndRays, ParallelLinesUsePointLineDistance) {
    EXPECT_FLOAT_EQ(geometry::distanceLineLine({0, 0, 0}, {1, 0, 0},
                                               {0, 2, 0}, {1, 0, 0}), 2.0);
}

TEST(GeometryLinesAndRays, CoincidentLinesAreZeroApart) {
    EXPECT_NEAR(geometry::distanceLineLine({0, 0, 0}, {1, 0, 0},
                                           {5, 0, 0}, {2, 0, 0}), 0.0, 1e-6);
}

TEST(GeometryLinesAndRays, GeneralSkewCase) {
    // (p2-p1).(v1 x v2) / |v1 x v2| = 3/sqrt(3) = sqrt(3)
    EXPECT_NEAR(geometry::distanceLineLine({1, 2, 3}, {1, 1, 0},
                                           {4, 0, 1}, {0, 1, 1}),
                std::sqrt(3.0f), 1e-5);
}
