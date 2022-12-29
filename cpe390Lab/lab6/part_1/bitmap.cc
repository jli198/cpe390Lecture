#include <fstream>
#include "bitmap.hh"
#include <webp/decode.h>
#include <webp/encode.h>
#include <random>

using namespace std;
/*
  Lab 6 - Part 1
	AUTHOR: JLi, Xavion
	CITE: Ryan (idea to find length of grid space through division)
	PLEDGE: "I pledge my honor that I have abided by the Stevens Honor System" ~JLi, Xavion
*/

/*
	In order to compile you will need to install libwebp, a new graphics
	standard from google. Most image programs won't yet work with webp,
	which is better compression than jpeg in general.

	In order to install under msys2: 
	https://packages.msys2.org/package/mingw-w64-x86_64-libwebp

	In order to access a particular element of this bitmap (x,y) use the
	following equation point(x,y) does this

	y*w + x

	this works because the first point is 0*w+0 = 0, the second would be 0*w+1

	one row down would be 1*w + 0
 */


bitmap::bitmap(uint32_t w, uint32_t h, uint32_t color) : w(w), h(h), rgb(new uint32_t[w*h]) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}

bitmap::~bitmap() {
	delete [] rgb;
}

void bitmap::clear(uint32_t color) {
	for (uint32_t i = 0; i < w*h; i++)
		rgb[i] = color;
}
void bitmap::horiz_line(uint32_t x1, uint32_t x2, uint32_t y, uint32_t color) {
  // TODO: implement this
  for (uint32_t i = y * w + x1; i < y * w + x2;
       i++)  // start at (x1, y) to (x2, y)
    rgb[i] = color;
}

void bitmap::vert_line(uint32_t y1, uint32_t y2, uint32_t x, uint32_t color) {
  // TODO: implement this
  for (uint32_t i = y1 * w + x; i < y2 * w + x;
       i += w)  // start at (x, y1) to (x, y2)
    rgb[i] = color;
}
/*
1 0 0 0 0
1 0 0 0 0
1 0 0 0 0
*/

void bitmap::fill_rect(uint32_t x0, uint32_t y0, uint32_t w, uint32_t h,
                       uint32_t color) {
  // TODO: implement this
  for (uint32_t i = 0; i < h; i++)
    horiz_line(x0, x0 + w, y0 + i, color);  // start at (x0, y0) to (x0+w, y0+i)
}

void bitmap::rect(uint32_t x0, uint32_t y0, uint32_t w, uint32_t h,
                  uint32_t color) {
  // TODO: implement this
  horiz_line(x0, x0 + w, y0, color);
  horiz_line(x0, x0 + w, y0 + h, color);
  vert_line(y0, y0 + h, x0, color);
  vert_line(y0, y0 + h, x0 + w, color);
}

void bitmap::grid(uint32_t x0, uint32_t y0, uint32_t w, uint32_t h,
                  uint32_t divx, uint32_t divy, uint32_t color) {
  // TODO: implement this

  int initrectx = x0 + w;
  int initrecty = y0 + h;
  int colorSet = color;
  horiz_line(x0, x0 + w, y0, color);
  horiz_line(x0, x0 + w, y0 + h, color);
  vert_line(y0, y0 + h, x0, color);
  vert_line(y0, y0 + h, x0 + w, color);
  int xlength = initrectx - x0;
  int ylength = initrecty - y0;
  int gridspacex = xlength / divx;
  int gridspacey = ylength / divy;
  int lineatx = x0;
  int lineaty = y0;
  for (int i = 0; i < divx; i++) {
    vert_line(y0, initrecty, lineatx, colorSet);
    lineatx += gridspacex;
  }
  for (int i = 0; i < divy; i++) {
    horiz_line(x0, initrectx, lineaty, colorSet);
    lineaty += gridspacey;
  }
}

/*for(uint32_t i = 0; i < w * h; i++) {
  horiz_line(x0, x0 + w, y0+i, color);
  vert_line(y0, y0+h, x0+i, color);

}
}
*/
std::default_random_engine gen;

// https://stackoverflow.com/questions/22853349/how-to-generate-random-32bit-integers-in-c
void bitmap::random(uint32_t x0, uint32_t y0, uint32_t rw, uint32_t rh) {
  // TODO: implement this
  int x1, y1;
  rect(x0, y0, rw, rh, 0xFFFF0000);
  for (int i = 1; i < 100; i++) {
    x1 = rand() % rw + x0;
    y1 = rand() % rh + y0;
    rgb[y1 * w + x1] = 0x00FF00FF;
    /*cout <<"X is at: "<< x1 << endl;
    cout << "Y is at: " << y1 << endl;

    cout << "combined is: "<<y1 * w + x1 << endl;*/
  }
}

void bitmap::circle(uint32_t x, uint32_t y, uint32_t d, uint32_t color) {
  // TODO: implement this

  int x1, y1;
  int radius = d / 2;
  int rr = radius * radius;
  int xx, yy;
  int negy1;
  for (x1 = -radius; x1 < radius; x1++) {
    xx = x1 * x1;
    yy = rr - xx;
    y1 = sqrt(yy) + y;

    rgb[y1 * w + x1 + x] = color;
    negy1 = -1 * sqrt(yy) + y;
    rgb[negy1 * w + x1 + x] = color;
  }
}

// https://stackoverflow.com/questions/1201200/fast-algorithm-for-drawing-filled-circles
void bitmap::fill_circle(uint32_t x0, uint32_t y0, uint32_t d, uint32_t color) {
  // TODO: implement this

  int x1, y1;
  int radius = d / 2;
  int rr = radius * radius;
  int xx, yy;
  int negy1;
  for (x1 = -radius; x1 < radius; x1++) {
    xx = x1 * x1;
    yy = rr - xx;
    y1 = sqrt(yy) + y0;
    negy1 = -1 * sqrt(yy) + y0;
    vert_line(negy1, y1, x1 + x0, color);
    /*cout << "Y1 is at " << y1 << endl;
    cout << "x1 is at " << x1 + x0 << endl;
    cout << "negy1 is " << negy1 << endl;*/
  }
}

// https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
// extra credit +50
void bitmap::line(int32_t x1, int32_t y1, int32_t x2, int32_t y2,
                  uint32_t color) {
  // TODO: optional for +50
}

// https://en.wikipedia.org/wiki/Xiaolin_Wu%27s_line_algorithm
//  extra credit +50
void bitmap::wuline(uint32_t x1, uint32_t y1, uint32_t x2, uint32_t y2,
                    uint32_t color) {
  // TODO: optional for +50
}

void bitmap::save(const char filename[]) {
  uint8_t* out;
  size_t s = WebPEncodeRGBA((uint8_t*)rgb, w, h, 4 * w, 100, &out);
  ofstream f(filename, ios::binary);
  f.write((char*)out, s);
  WebPFree(out);
}

// not required for this assignment but +50 if you look it up and do it
//  but if you do, test it by loading in a picture, modify, and save it out
void bitmap::load(const char filename[]) {
  uint8_t* out;
  // TODO:
  //	int s= WebPGetInfo(rgb, w*h*4, w, h, out);
}

void bitmap::flood_fill_allcolor(uint32_t x, uint32_t y, uint32_t findcolor,uint32_t replace_color){
  
  int currentColor = rgb[y * w + x];
  if((currentColor!=replace_color)&&(currentColor==findcolor)){
    
  

    //west
    if(((x-1)>0)&&((x-1)<=(w-1))){
      rgb[y * w + x]=replace_color;
      flood_fill_allcolor(x - 1, y,findcolor,replace_color);
      
    }
    //north
    if (((y - 1) > 0) && ((y - 1) <= (h - 1))) {
      rgb[y * w + x] = replace_color;
      flood_fill_allcolor(x, y-1, findcolor, replace_color);
    }
    //east
    if (((x + 1) > 0) && ((x + 1) <= (w - 1))) {
      rgb[y * w + x] = replace_color;
      flood_fill_allcolor(x + 1, y, findcolor, replace_color);
    }
    //south
    if (((y + 1) > 0) && ((y + 1) <= (h - 1))) {
      rgb[y * w + x] = replace_color;
      flood_fill_allcolor(x, y + 1, findcolor, replace_color);
    }
}


}

