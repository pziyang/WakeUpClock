#include "Clock.h"
#include "led-matrix.h"
#include "graphics.h"

using rgb_matrix::GPIO;
using rgb_matrix::RGBMatrix;
using rgb_matrix::Canvas;

bool LedClock::GetTimeAndDate()
{
    time_t t = time(0);   // get time and date now
    timeinfo_ = localtime(&t);

    return true;
}

bool LedClock::DisplayTime()
{
    //format time string to HH:MM:AM/PM
    char buffer[8];
    strftime (buffer,8,"%I:%M%p.",timeinfo_);

    rgb_matrix::DrawText(canvas_, font_, x_, y_ + font_.baseline(), color_, buffer);

    return true;
}

//bool LedClock::DisplayDate()
//{
//    //format day string (Mon/Tues/.../Fri)
//    char buffer_day[4];
//    strftime (buffer_day,4,"%a",timeinfo_);

//    //print day
//    rgb_matrix::DrawText(matrix_, font_, x_, y_ + font.baseline(), color, buffer_day);

//    //format date string ( MM/DD )
//    char buffer_date[5];
//    strftime (buffer_date,5,"%m/%d",timeinfo_);

//    //print date
//    rgb_matrix::DrawText(matrix_, font_, x_, y_ + font.height(), color, buffer_date);

//    return true;
//}

//bool LedClock::CheckSunRise() {
    
//}

void LedClock::Run()
{
    while (running()) {

        //time

        //weather info

        //weather graphic
    }
}
