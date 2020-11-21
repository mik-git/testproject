#include "figure.h"
#include "rectangle.h"
#include "square.h"
#include "oval.h"
#include "circle.h"
#include "triangle.h"

#include <iostream>


int main()
{
  std::cout << "Hello World!" << std::endl;
  Rectangle r{30,50};
  r.draw();
  Square s{50};
  s.draw();
  Oval o{25,60};
  o.draw();
  Circle c{35};
  c.draw();
  Triangle t{52,70};
  t.draw();
  return 0;
}
