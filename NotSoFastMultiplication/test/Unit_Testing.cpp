#include <gtest/gtest.h>
#include "PointsInTriangle.hpp"

TEST(PointsInTriangleTest, trivialCases) {

	using Point = geometry::Point;
	using Triangle = geometry::Triangle;

	Point a(0,0), b(0,2), c(2,0), p(0,0);
	Triangle t(a,b,c, 0);

	EXPECT_EQ(std::string("E"), t.determine_exact_position(p));

	p = Point(0,1);
	EXPECT_EQ(std::string("E"), t.determine_exact_position(p));
}

TEST(PointsInTriangleTest, inside) {

	using Point = geometry::Point;
	using Triangle = geometry::Triangle;

	Point a(630, 421), b(326, 242), c(561, 432), p(478, 332);
	Triangle t(a, b, c, 0);

	EXPECT_EQ(std::string("I"), t.determine_exact_position(p));

	a = Point(975, 75);
	b = Point(324, 166);
	c = Point(343, 28);
	p = Point(650, 120);
	t = Triangle(a,b,c,0);

	ASSERT_EQ(std::string("I"), t.determine_exact_position(p));
}

TEST(PointsInTriangleTest, edge) {

	using Point = geometry::Point;
	using Triangle = geometry::Triangle;

	Point a(378, 212), b(380, 550), c(840, 735), p(379, 381);
	Triangle t(a, b, c, 0);

	EXPECT_EQ(std::string("E"), t.determine_exact_position(p));
}


TEST(PointsInTriangleTest, outside) {

	using Point = geometry::Point;
	using Triangle = geometry::Triangle;

	Point a(591, 916), b(765, 191), c(487, 490), p(678, 554);
	Triangle t(a, b, c, 0);

	EXPECT_EQ(std::string("O"), t.determine_exact_position(p));
}

int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}