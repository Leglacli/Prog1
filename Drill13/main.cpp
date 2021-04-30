/* 
g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -w -o main `fltk-config --ldflags --use-images`
*/

#include "Graph.h"
#include "Simple_window.h"

int main()
{
	using namespace Graph_lib;

	// 1.
	Point tl {100,100};
	Simple_window win {tl, 1000, 800, "Drill14"};

	// 2.
	int grid_size = 800;
	Lines grid;

	for (int x=100; x<=grid_size; x+=100)
		grid.add(Point{x,0}, Point{x,grid_size});
	for (int y=100; y<grid_size; y+=100)
		grid.add(Point{0,y}, Point{grid_size,y});

	win.attach(grid);

	// 3.
	Vector_ref<Rectangle> rects;
	for (int i=0; i<8; i++)
	{
		rects.push_back(new Rectangle(Point{i*100, i*100}, 100, 100));
		rects[i].set_fill_color(Color::red);
		win.attach(rects[i]);
	}

	// 4.
	Vector_ref<Image> images;
	int imgx = 200;
	for (int i=0; i<3; i++)
	{
		images.push_back(new Image(Point{imgx,0}, "image.jpg"));
		win.attach(images[i]);
		imgx+=200;
	}

	// 5.
	Image wsb (Point{0,0}, "wsb.jpg");
	win.attach(wsb);
	int dy = 100;
	int dx = -700;

	for (int i=1;i<=8;i++)
		for(int j=1;j<=8;j++)
		if (j==8)
		{	
			if (i==8) break;
			win.wait_for_button();
			wsb.move(dx,dy);
		}
		else
		{
		win.wait_for_button();
		wsb.move(100,0);
		}
	

	win.wait_for_button();
}
