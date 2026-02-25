#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_floating_point.hpp>
#include <MathVier/MathVier.hpp>

TEST_CASE("Vec2 construtor", "[vec2]") {
   MathVier::Vec2<float> v(2.0f, 3.0f);
   REQUIRE(v.x == 2.0f);
   REQUIRE(v.y == 3.0f);
}

