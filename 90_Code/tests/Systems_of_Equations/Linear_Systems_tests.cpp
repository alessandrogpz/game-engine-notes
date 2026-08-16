#include <gtest/gtest.h>

import systems_linear_systems;

TEST(SystemsLinearSystems, Initialization) {
    // Just verify the placeholder module runs cleanly
    EXPECT_NO_THROW(systems::test_systems_linear_systems());
}
