#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "figure.h"

class Rectangle : public Figure
{
public:
  explicit Rectangle(int width, int height);
  ~Rectangle() override = default;
  void draw() override;
};

#endif // RECTANGLE_H
