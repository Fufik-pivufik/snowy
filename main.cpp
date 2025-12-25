#include "./helpf/_helpfs.h"
#include "./helpf/_matrix.h"
#include "./helpf/_shapes.h"
#include <asm-generic/ioctls.h>
#include <chrono>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <thread>
#include <unistd.h>

int main()
{
  const long drops_c = 60;
  struct winsize ws;
  if (ioctl(STDIN_FILENO, TIOCGWINSZ, &ws) == -1)
  {
    return -1;
  }

  long height = ws.ws_row;
  long width = ws.ws_col;
  monas::Matrix m = monas::Matrix(height, width);
  std::vector<monas::Point> drops;
  std::vector<int> speeds;
  for (long i = 0; i < drops_c; ++i)
  {
    short colr = static_cast<short>(monas::randint(150, 200));
    long x = monas::randint(0, width - 1);
    long y = monas::randint(0, height - 1);

    int speed = monas::randint(1, 3);
    monas::Point drop{y, x, 3, colr, colr, short(colr + (short)55)};
    drops.push_back(drop);
    speeds.push_back(speed);
  }

  while (1)
  {
    std::cout << "\e[?25l";
    m.draw(drops);
    m.display();

    for (int i = 0; i < drops_c; ++i)
    {
      drops[i].x = (drops[i].x + speeds[i]) % width;
      drops[i].y = (drops[i].y + 1) % height;
    }
    m.clear();

    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    system("clear");
    std::cout << "\e[?25h";
  }

  return 0;
}
