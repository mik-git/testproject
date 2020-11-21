#include "rectangle.h"
#include <iostream>
#include <graphics.h>


Rectangle::Rectangle(int width, int height) : Figure (width, height)
{

}

void Rectangle::draw()
{
  if ( width() <= 1 || height() <= 1 )   {
    return;
  }
  int gd = DETECT;
  int gm;

  int left = 10;
  int top = 10;
  int right = left + width();
  int bottom = top + height();

  initgraph(&gd, &gm, "");

  rectangle(left, top, right, bottom);

  getch();

  closegraph();

}
