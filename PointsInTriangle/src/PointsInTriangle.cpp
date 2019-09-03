#include "PointsInTriangle.hpp"

int geometry::Point::get_m_x_coordinate() const
{
	return m_x_coordinate;
}

int geometry::Point::get_m_y_coordinate() const
{
	return m_y_coordinate;
}

geometry::Triangle::Position geometry::Triangle::calculate_exact_pos_relative_to_triangle(Point t_p)
{

	return Position::OUTSIDE;
}

std::string geometry::Triangle::determine_exact_position(Point t_p)
{
	Position exact_position = calculate_exact_pos_relative_to_triangle(t_p);
	switch (exact_position) {
	  case Position::INSIDE:
		  return std::string("I");
	  case Position::EDGE:
		  return std::string("E");
	  default:
		  return std::string("O"); // we assume it is outside
	}
}

geometry::Straight_line::Straight_line(Point t_first, Point t_second)
{
	if (t_first.get_m_x_coordinate - t_second.get_m_x_coordinate == 0) {
		m_a_coefficient = std::numeric_limits<double>::infinity();
		m_b_coefficient = 
	}

	m_a_coefficient = (t_first.get_m_y_coordinate - t_second.get_m_y_coordinate)
}

geometry::Straight_line::Position_relative_to_straight_line geometry::Straight_line::determine_position(Point t_p)
{
	return Position_relative_to_straight_line();
}