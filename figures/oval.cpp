#include "oval.h"
#include <iostream>
#include <graphics.h>

Oval::Oval(int width, int height) : Figure(width, height)
{

}

void Oval::draw()
{
  std::cout << "OVAL" << std::endl;
  if ( width() <= 1 || height() <= 1 )   {
    return;
  }
  int gd = DETECT;
  int gm;

  int x = width() + 10;
  int y = height() + 10;
  int start_angle = 0;
  int end_angle = 360;

  initgraph(&gd, &gm, "");

  ellipse(x, y, start_angle, end_angle, width(), height());

  getch();

  closegraph();


}
