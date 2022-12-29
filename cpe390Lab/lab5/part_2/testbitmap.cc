#include "bitmap.hh"
#include <iostream>
#include <fstream>

using namespace std;

// colors are in hex: 8 digits representing AABBGGRR
// (transparency, Blue, Green, Red)

int main() {
	bitmap b(1024, 800, 0xFF000000);
	b.clear(0xFF000000);
	b.random(500, 400, 300, 200);
	b.horiz_line(100, 400, 50, 0xFF000080);
	b.horiz_line(100, 400, 100, 0xFF0000FF);
	b.horiz_line(100, 400, 170, 0xFF0000FF);
	b.vert_line(100, 180, 110, 0xFF0000FF);
	b.vert_line(100, 180, 350, 0xFF0000FF);
	b.vert_line(100, 400, 100, 0x00FF00FF);
	b.grid(600,500, 200, 200, 6, 6, 0xFFFF0000);
	for (uint32_t x = 200; x <= 600; x += 100)
		b.fill_rect(x,200, 50,50, 0xFF00FFFF);
	for (uint32_t x = 200; x <= 600; x += 100)
		b.fill_circle(x,400, 50, 0xFF00FFFF);
	b.rect(200,260, 50,50, 0xFFFFFFFF);
	b.circle(200,500, 50, 0xFFFFFFFF);
	
	// optional functions: line, wuline, load if you want to test your bonus parts:

	b.save("test.webp");
}
