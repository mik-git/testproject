#ifndef CIRCLE_H
#define CIRCLE_H

#include "oval.h"

class Circle : public Oval
{
public:
  explicit Circle(int diametr);
  ~Circle() override = default;
};

#endif // CIRCLE_H
