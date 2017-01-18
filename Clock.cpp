#include "Clock.h"

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
    strftime (buffer,8,"%I:%M%p.",timeinfo);

    rgb_matrix::DrawText(matrix_, font, x, y + font.baseline(), color, buffer);

    return true;
}

bool LedClock::DisplayDate()
{
    //format day string (Mon/Tues/.../Fri)
    char buffer_day[4];
    strftime (buffer_day,4,"%a",timeinfo);

    //print day
    rgb_matrix::DrawText(matrix_, font, x, y + font.baseline(), color, buffer_day);

    //format date string ( MM/DD )
    char buffer_date[5];
    strftime (buffer_date,5,"%m/%d",timeinfo);

    //print date
    rgb_matrix::DrawText(matrix_, font, x, y + font.height(), color, buffer_date);

    return true;
}

bool LedClock::CheckSunRise() {
    
}

void LedClock::Run()
{
    while (running()) {

        //time

        //weather info

        //weather graphic
    }
}
