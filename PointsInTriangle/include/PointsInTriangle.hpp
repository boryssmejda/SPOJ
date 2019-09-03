#include <array>
#include <iostream>
#include <string>
#include <limits>

namespace geometry {
	class Point;
	class Triangle;

	class Point {
	private:
		int m_x_coordinate, m_y_coordinate;
	public:
		Point(int t_x, int t_y) :
			m_x_coordinate{ t_x },
			m_y_coordinate{ t_y }{}

		int get_m_x_coordinate() const;
		int get_m_y_coordinate() const;

		friend class Triangle;
	};

	class Triangle {
	  Point m_a_vertex, m_b_vertex, m_c_vertex;
	  int m_id_num;

	  enum class Position {
	    INSIDE = 0, OUTSIDE = 1, EDGE = 2
	  };

	  Position calculate_exact_pos_relative_to_triangle(Point t_p);
	public:
	  Triangle(Point t_a, Point t_b, Point t_c, int t_id) :
			m_a_vertex{ t_a },
			m_b_vertex{ t_b },
			m_c_vertex{ t_c },
			m_id_num{ t_id }{}

		std::string determine_exact_position(Point t_p);
	};

	class Straight_line {

	private:
		double m_a_coefficient, m_b_coefficient;
	public:
		Straight_line(Point t_first, Point t_second);
		
		enum class Position_relative_to_straight_line {
			BELOW = 0, ABOVE = 1, EXACTLY_ON_LINE = 2
		};

		Position_relative_to_straight_line determine_position(Point t_p);
	};
}