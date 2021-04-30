/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{
	using namespace Graph_lib;

	
	Point tl {100,100};
	Simple_window win {tl, 800,500, "My Window"};

	Axis xa {Axis::x, Point{50,350}, 300, 30, "X Axis"};
	xa.set_color(Color::green);
	xa.label.set_color(Color::blue);
	win.attach(xa);

	Axis ya {Axis::y, Point{50,350}, 300, 30, "Y Axis"};
	ya.set_color(Color::red);
	ya.label.set_color(Color::cyan);
	win.attach(ya);

	Function sine {sin,0,100,Point{20,150},1000,50,50};
	sine.set_color(Color::dark_blue);
	win.attach(sine);

	Polygon poly;
	Point A{400,300};
	Point B{450,200};
	Point C{500,300};
	poly.add(A);
	poly.add(B);
	poly.add(C);
	poly.set_color(Color::yellow);
	poly.set_style(Line_style(Line_style::dash,6));
	win.attach(poly);

	Point corner_point{100,100};
	Rectangle r {corner_point, 200, 100};
	r.set_color(Color::green);
	r.set_fill_color(Color::blue);
	win.attach(r);

	Closed_polyline poly_rect;
	poly_rect.add(Point{300,150});
	poly_rect.add(Point{400,150});
	poly_rect.add(Point{400,300});
	poly_rect.add(Point{300,300});
	poly_rect.add(Point{150,225});
	poly_rect.set_color(Color::red);
	poly_rect.set_style(Line_style(Line_style::dot,4));
	poly_rect.set_fill_color(Color::black);
	win.attach(poly_rect);

	Text t {Point{300,50}, "Hello World!"};
	t.set_font(Font::times_bold);
	t.set_font_size(25);
	win.attach(t);

	Image img {Point{25,25}, "badge.jpg"};
	img.move(100,200);
	win.attach(img);



	win.wait_for_button();
}