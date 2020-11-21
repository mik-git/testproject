#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"

class Square : public Rectangle
{
public:
  explicit Square(int size);
  ~Square() override = default;
};

#endif // SQUARE_H
