#include "./_helpfs.h"
#include "_shapes.h"

long monas::randint(long low, long high)
{
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> distrib(low, high);
  return distrib(gen);
}

void monas::pointcp(Point& res, const Point& source)
{
  res.b = source.b;
  res.g = source.g;
  res.r = source.r;

  res.val = source.val;
  res.x = source.x;
  res.y = source.y;
}
