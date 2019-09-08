#include <array>
#include <iostream>
#include <string>
#include <limits>
#include <tuple>
#include <cstdlib>

namespace geometry {

	class Point;
	class Triangle;
	bool shouldFinish(Point a, Point b, Point c, Point p);

	class Point {
	private:
		int m_x_coordinate, m_y_coordinate;
	public:
		Point() : m_x_coordinate{0}, m_y_coordinate{0}{}
		Point(int t_x, int t_y) :
			m_x_coordinate{ t_x },
			m_y_coordinate{ t_y }{}

		Point& operator = (const Point& t);

		int get_m_x_coordinate() const;
		int get_m_y_coordinate() const;

		friend std::istream& operator>> (std::istream& input, geometry::Point& p);
		friend class Triangle;
	};

	class Triangle {
	  Point m_a_vertex, m_b_vertex, m_c_vertex;
	  int m_id_num;

	  enum class Position {
	    INSIDE = 0, OUTSIDE = 1, EDGE = 2
	  };

	  double calculate_triangle_area(Point A, Point B, Point C);
	  auto calculate_group_of_useful_areas(Point t_p);
	  bool is_outside(Point t_p);
	  bool is_on_edge(Point t_p);
	  Position calculate_exact_pos_relative_to_triangle(Point t_p);
	public:
	  Triangle(Point t_a, Point t_b, Point t_c, int t_id) :
			m_a_vertex{ t_a },
			m_b_vertex{ t_b },
			m_c_vertex{ t_c },
			m_id_num{ t_id }{}

		std::string determine_exact_position(Point t_p);
	};

}