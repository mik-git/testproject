#ifndef OVAL_H
#define OVAL_H

#include "figure.h"

class Oval : public Figure
{
public:
  explicit Oval( int width, int height );
  ~Oval() override = default;
  void draw() override;
};

#endif // OVAL_H
