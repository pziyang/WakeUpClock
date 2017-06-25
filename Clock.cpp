#include "Clock.h"
#include "led-matrix.h"
#include "graphics.h"

#include <unistd.h>
#include <math.h>

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

bool LedClock::GetTimeAndDate()
{
    time_t t = time(0);   // get time and date now
    timeinfo_ = localtime(&t);

    return true;
}

bool LedClock::SetFontColor()
{

    if (timeinfo_.tm_hour > 22 || timeinfo_.tm_hour < 8)
    {
        pcolor_->r = 255;
        pcolor_->g = 255;
        pcolor_->b = 0;
    }
    else
    {
        pcolor_ = new rgb_matrix::Color(255, 255, 0);
    }

    return true;
}

bool LedClock::DisplayTime()
{
    //format time string to HH:MM:AM/PM
    char buffer[8];
    strftime(buffer,8,"%H:%M",timeinfo_);

    rgb_matrix::Color color(255, 255, 0);

    int x(0), y(0);

    rgb_matrix::DrawText(canvas_, font_, x, y + font_.baseline(),
                         color, buffer);

    return true;
}

bool LedClock::DisplayDate()
{
    //format day string (Mon/Tues/.../Fri)
    char buffer_day[4];
    strftime (buffer_day,4,"%a",timeinfo_);

    //print day
    //rgb_matrix::DrawText(canvas_, font_, x_, y_ + font_->baseline(), color_->Color, buffer_day);

    //format date string ( MM/DD )
    char buffer_date[5];
    strftime (buffer_date,5,"%m/%d",timeinfo_);

    //print date
    //rgb_matrix::DrawText(canvas_, font_, x_, y_ + font_->height(), color_->Color, buffer_date);

    return true;
}

bool LedClock::CheckSunRise() {
    
}

void LedClock::Run()
{
    while (running()) {

        //time
        GetTimeAndDate();
        DisplayTime();

        //weather info

        //weather graphic

        sleep(1);
    }
}
