// Utility base class for continuously updating the canvas.
#ifndef RPI_THREADED_CANVAS_MANIPULATOR_H
#define RPI_THREADED_CANVAS_MANIPULATOR_H

#include <string>
#include <time.h>
#include <mutex>
#include <thread>


#include "thread.h"
#include "canvas.h"

class LedClock : public ThreadedCanvasManipulator {
    public:
        LedClock(Canvas *canvas) : ThreadedCanvasManipulator(canvas), matrix_(canvas) {}

        //main thread
        virtual void Run();

        bool GetTimeAndDate();
        bool DisplayTime();
        bool DisplayDate();
        
        bool CheckSunRise();
        bool WakeLight();
        
        bool GetWeather();
        bool DisplayWeather();

    private:
        struct tm *timeinfo_;

        Color color_(255, 255, 0);
        const char *bdf_font_file_ = NULL;
        int x_origin_ = 0;
        int y_origin_ = 0;
        int brightness_ = 100;
        
        RGBMatrix * const matrix_;
        
        std::mutex mlock_;

};
