#include "Clock.h"
#include "led-matrix.h"
#include "graphics.h"

#include <unistd.h>
#include <math.h>

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

bool LedClock::SetFontColor()
{
    continuum_ += 1;
    continuum_ %= 3 * 255;
    int r = 0, g = 0, b = 0;
    if (continuum_ <= 255)
    {
      int c = continuum_;
      b = 255 - c;
      r = c;
    }
    else if (continuum_ > 255 && continuum_ <= 511)
    {
      int c = continuum_ - 256;
      r = 255 - c;
      g = c;
    }
    else
    {
      int c = continuum_ - 512;
      g = 255 - c;
      b = c;
    }

    pcolor_->r = r;
    pcolor_->g = g;
    pcolor_->b = b;

    return true;
}

bool LedClock::DisplayTime()
{
    // get time and date now
    time_t t = time(0);
    timeinfo_ = localtime(&t);

    //format time string to HH:MM:AM/PM
    char buffer_time[8];
    strftime(buffer_time,8,"%I:%M",timeinfo_);

    int x_time = 1;
    int y_time = font_.baseline()-1;

    canvas_->Clear();
    rgb_matrix::DrawText(canvas_, font_, x_time, y_time, *pcolor_, buffer_time);

    //format time string to HH:MM:AM/PM
    char buffer[3];
    strftime(buffer,3,"%p",timeinfo_);

    int x = 10;
    int y = font_.height() + font_.baseline() - 2;

    rgb_matrix::DrawText(canvas_, font_, x, y, *pcolor_, buffer);

    return true;
}

bool LedClock::DisplayDate()
{
    // get time and date now
    time_t t = time(0);
    timeinfo_ = localtime(&t);

    //format day string (Mon/Tues/.../Fri)
    char buffer_day[4];
    strftime (buffer_day,4,"%a",timeinfo_);

    int x_day = 7;
    int y_day = font_.baseline()-1;

    //print day
    canvas_->Clear();
    rgb_matrix::DrawText(canvas_, font_, x_day, y_day, *pcolor_, buffer_day);

    //format date string ( DDMMM )
    char buffer_date[6];
    strftime (buffer_date,6,"%d%h",timeinfo_);

    int x_date = 1;
    int y_date = font_.height() + font_.baseline() - 2;

    //print date
    rgb_matrix::DrawText(canvas_, font_, x_date, y_date, *pcolor_, buffer_date);

    return true;
}

bool LedClock::CheckSunRise() {

    return true;
    
}

void LedClock::Run()
{
    while (running()) {

        //time
        for (int i=0; i<100; i++)
        {
            SetFontColor();
            DisplayTime();
            usleep(100 * 1000);
        }

        //date
        for (int i=0; i<100; i++)
        {
            SetFontColor();
            DisplayDate();
            usleep(100 * 1000);
        }

        //weather info

        //weather graphic

        sleep(1);
        canvas_->Clear();
    }
}
