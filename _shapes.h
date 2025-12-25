#include <cmath>
#include <vector>
#pragma once

namespace monas
{

typedef struct
{
  long y;
  long x;
  int val;
  // color for points;
  short r = 255, g = 255, b = 255;
} Point;

void pointcp(Point& res, const Point& source);

inline long distance_int(const Point& a, const Point& b)
{
  return std::ceil(
      std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)));
}

class Line
{

private:
  Point a, b;

  long length;

public:
  std::vector<Point> points;
  Line(Point a, Point b) : a(a), b(b)
  {
    length = distance_int(a, b);
    long max_x, min_x, max_y, min_y;

    if (a.x > b.x)
    {
      max_x = a.x;
      min_x = b.x;
    }
    else
    {
      max_x = b.x;
      min_x = a.x;
    }

    if (a.y > b.y)
    {
      max_y = a.y;
      min_y = b.y;
    }
    else
    {
      max_y = b.y;
      min_y = a.y;
    }

    for (long y = min_y; y <= max_y; ++y)
      for (long x = min_x; x <= max_x; ++x)
      {
        Point p{y, x, a.val, a.r, a.g, a.b};
        if (is_on_line(p))
          points.push_back(p);
      }
  }
  bool is_on_line(const Point& p)
  {
    return (p.x - a.x) * (b.y - a.y) == (p.y - a.y) * (b.x - a.x);
  }
};

}; // namespace monas
