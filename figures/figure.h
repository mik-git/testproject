#ifndef FIGURE_H
#define FIGURE_H

class Figure
{
public:
  explicit Figure( int width, int height);
  virtual ~Figure() = default;
  virtual void draw() = 0;
  int width() { return  width_; }
  int height() { return height_; }

private:
  int width_;
  int height_;

};

#endif // FIGURE_H
