#include "triangle.h"
#include <iostream>
#include <graphics.h>

Triangle::Triangle(int width, int height) : Figure( width, height )
{

}

void Triangle::draw()
{
  int gd = DETECT;
  int gm;
  initgraph(&gd, &gm, "");

  int x1 = 10;
  int y1 = 10;

  int x2 = x1 + width();
  int y2 = y1;

  int x3 = x1 + (x2-x1)/2;
  int y3 = 10 + height();

  line(x1,y1,x2,y2);
  line(x2,y2,x3,y3);
  line(x3,y3,x1,y1);

  getch();

  closegraph();
}
