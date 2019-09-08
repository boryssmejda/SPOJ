#include "PointsInTriangle.hpp"

bool geometry::shouldFinish(Point a, Point b, Point c, Point p) {

	if (!a.get_m_x_coordinate() && !b.get_m_x_coordinate() && !c.get_m_x_coordinate() && !p.get_m_x_coordinate()) {

		if (!a.get_m_y_coordinate() && !b.get_m_y_coordinate() && !c.get_m_y_coordinate() && !p.get_m_y_coordinate()) {
			return true;
		}
	}
	return false;
}

geometry::Point& geometry::Point::operator=(const Point& t)
{
	this->m_x_coordinate = t.get_m_x_coordinate();
	this->m_y_coordinate = t.get_m_y_coordinate();

	return *this;
}

int geometry::Point::get_m_x_coordinate() const
{
	return m_x_coordinate;
}

int geometry::Point::get_m_y_coordinate() const
{
	return m_y_coordinate;
}

double geometry::Triangle::calculate_triangle_area(Point A, Point B, Point C)
{
	int first_part = A.m_x_coordinate * (B.m_y_coordinate - C.m_y_coordinate);
	int second_part = B.m_x_coordinate * (C.m_y_coordinate - A.m_y_coordinate);
	int third_part = C.m_x_coordinate * (A.m_y_coordinate - B.m_y_coordinate);

	return abs((first_part + second_part + third_part)) / 2.0;
}

auto geometry::Triangle::calculate_group_of_useful_areas(Point t_p)
{
	int triangle_area = static_cast<int>(std::round(calculate_triangle_area(m_a_vertex, m_b_vertex, m_c_vertex)));

	double area_abp = calculate_triangle_area(m_a_vertex, m_b_vertex, t_p);
	double area_acp = calculate_triangle_area(m_a_vertex, m_c_vertex, t_p);
	double area_bcp = calculate_triangle_area(m_b_vertex, m_c_vertex, t_p);

	int area_of_partial_triangles = static_cast<int>(std::round(area_abp + area_acp + area_bcp));

	return std::make_tuple(triangle_area, area_abp, area_acp, area_bcp, area_of_partial_triangles);
}

bool geometry::Triangle::is_outside(Point t_p)
{
	auto [triangle_area, area_abp, area_acp, area_bcp, area_of_partial_triangles] = calculate_group_of_useful_areas(t_p);

	if (triangle_area == area_of_partial_triangles) {
		return false;
	}
	else {
		return true;
	}
}

bool geometry::Triangle::is_on_edge(Point t_p)
{
	auto [triangle_area, area_abp, area_acp, area_bcp, area_of_partial_triangles] = calculate_group_of_useful_areas(t_p);

	if (area_abp == 0 || area_acp == 0 || area_bcp == 0) {
		return true;
	}
	else {
		return false;
	}
}

geometry::Triangle::Position geometry::Triangle::calculate_exact_pos_relative_to_triangle(Point t_p)
{
	if (is_outside(t_p)) {
		return Position::OUTSIDE;
	}

	if (is_on_edge(t_p)) {
		return Position::EDGE;
	}
	else {
		return Position::INSIDE;
	}
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

std::istream& geometry::operator>>(std::istream& input, geometry::Point& p)
{
	return input >> p.m_x_coordinate >> p.m_y_coordinate;
}
