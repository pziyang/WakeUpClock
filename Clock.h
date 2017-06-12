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
    LedClock(rgb_matrix::Canvas *canvas) :
        rgb_matrix::ThreadedCanvasManipulator(canvas),
        color_(0,0,0)
    {
       canvas_ = canvas;
    }

    //main thread
    virtual void Run();

    bool GetTimeAndDate();
    bool DisplayTime();
//    bool DisplayDate();

//    bool CheckSunRise();
//    bool WakeLight();

//    bool GetWeather();
//    bool DisplayWeather();

private:
    struct tm *timeinfo_;

    rgb_matrix::Canvas *canvas_;

    rgb_matrix::Color color_;
    const char *bdf_font_file_ = NULL;
    int x_origin_ = 0;
    int y_origin_ = 0;
    int brightness_ = 100;

    int x_;
    int y_;

    rgb_matrix::Font font_;

    std::mutex mlock_;

};
