/*
g++ drill15graph.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -w -o drill15graph `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

double one(double x) { return 1; }
double slope(double x) { return x/2; }
double square(double x) { return x*x; }
double sloping_cos(double x) { return slope(x) + cos(x); }

int main()
{
	Point tl {100,100};

	constexpr int xmax = 600;
	constexpr int ymax = 600;

	constexpr int crossx = 300;
	constexpr int crossy = 300;

	constexpr int axis_scale = 30;
	constexpr int axis_length = 400;

	Simple_window win (tl,600,600, "Function graphs");

	Axis axis_x {Axis::x, Point{100, crossy}, axis_length, axis_length/axis_scale, "1 == 20"};
	Axis axis_y {Axis::y, Point{crossx, 500}, axis_length, axis_length/axis_scale, "1 == 20"};

	axis_x.set_color(Color::red);
	axis_y.set_color(Color::red);
	win.attach(axis_x);
	win.attach(axis_y);
	win.wait_for_button();


	Point origo{xmax/2, ymax/2};
	constexpr int r_min = -10;
	constexpr int r_max = 11;
	constexpr int x_scale = 20;
	constexpr int y_scale = 20;
	constexpr int number_of_points = 400;

	Function f1 {one, r_min, r_max, origo, number_of_points, x_scale, y_scale};

	Function f2 {slope, r_min, r_max, origo, number_of_points, x_scale, y_scale};

	Text label {Point{100,380}, "x/2"};

	Function f3 {square, r_min, r_max, origo, number_of_points, x_scale, y_scale};

	Function f4 {cos, r_min, r_max, origo, number_of_points, x_scale, y_scale};
	f4.set_color(Color::blue);

	Function f5 {sloping_cos, r_min, r_max, origo, number_of_points, x_scale, y_scale};

	win.attach(f1);
	win.attach(f2);
	win.attach(label);
	win.attach(f3);
	win.attach(f4);
	win.attach(f5);
	win.wait_for_button();

}