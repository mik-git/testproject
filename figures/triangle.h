#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure
{
public:
  explicit Triangle(int width, int height);
  ~Triangle() override = default;
  void draw() override;
};

#endif // TRIANGLE_H
