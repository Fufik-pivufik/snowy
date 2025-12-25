#include "./_shapes.h"
#include <iostream>
#include <stdio.h>
#include <vector>
#pragma once

namespace monas
{

const char SYMS[] = {' ', '#', '-', '*', '0'};

class Matrix
{
private:
  long h;
  long w;
  Point** matrix;

public:
  Matrix(long h, long w) : h(h), w(w)
  {
    matrix = new Point*[h];
    for (long i = 0; i < h; ++i)
    {
      matrix[i] = new Point[w];
      for (long j = 0; j < w; ++j)
        matrix[i][j].val = 0;
    }
  }

  void clear()
  {
    for (long i = 0; i < h; ++i)
      for (long j = 0; j < w; ++j)
      {
        Point& point = matrix[i][j];
        point.val = 0;
        point.r = point.g = point.b = 255;
      }
  }

  void draw(const std::vector<Point>& points)
  {
    for (Point point : points)
    {
      pointcp(this->matrix[point.y][point.x], point);
    }
  }

  void display()
  {
    for (long i = 0; i < h; ++i)
    {
      // std::cout << "|";
      for (long j = 0; j < w; ++j)
        if (matrix[i][j].val > 0)
          printf("\e[38;2;%d;%d;%dm█\e[0m", matrix[i][j].r, matrix[i][j].g,
                 matrix[i][j].b); // SYMS[matrix[i][j].val]);
        else
          printf(" ");

      // std::cout << "|" << std::endl;
      std::cout << std::endl;
    }
  }

  ~Matrix()
  {
    for (long i = 0; i < h; ++i)
      delete[] matrix[i];

    delete[] matrix;
  }
};

}; // namespace monas
