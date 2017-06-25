#include <string>
#include <time.h>
#include <mutex>
#include <thread>

#include "thread.h"
#include "led-matrix.h"
#include "threaded-canvas-manipulator.h"
#include "graphics.h"

class LedClock : public rgb_matrix::ThreadedCanvasManipulator
{
public:
  LedClock(rgb_matrix::Canvas *c)
    : ThreadedCanvasManipulator(c), canvas_(c)
  {
      //load font file
      font_.LoadFont("../rgb_led_matrix/fonts/6x12.bdf");

      //set default font color
      pcolor_ = new rgb_matrix::Color(255, 255, 0);
  }

  //main method
  void Run();

  //subroutines
  bool GetTimeAndDate();
  bool SetFontColor();

  bool DisplayTime();
  bool DisplayDate();

  bool CheckSunRise();

private:

  rgb_matrix::Canvas* const canvas_;

  int x_origin_ = 0;
  int y_origin_ = 0;
  int brightness_ = 100;

  int x_;
  int y_;

  rgb_matrix::Font font_;
  rgb_matrix::Color* pcolor_;

  std::mutex mlock_;

  struct tm *timeinfo_;

};
