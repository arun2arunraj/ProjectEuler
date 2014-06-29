#include "Problem19.h"

namespace projectEuler
{


// Constructor
Problem19::Problem19()
{
    
}


// Destructor
Problem19::~Problem19()
{

}


// Solver
void Problem19::Solve()
{
    map<int, int> daysInMonth;
    daysInMonth[0]  = 31; // January
    daysInMonth[1]  = 28; // February
    daysInMonth[2]  = 31; // March
    daysInMonth[3]  = 30; // April
    daysInMonth[4]  = 31; // May
    daysInMonth[5]  = 30; // June
    daysInMonth[6]  = 31; // July
    daysInMonth[7]  = 31; // August
    daysInMonth[8]  = 30; // September
    daysInMonth[9]  = 31; // October
    daysInMonth[10] = 30; // November
    daysInMonth[11] = 31; // December

    map<int, string> weekdayNames;
    weekdayNames[0] = "Monday";
    weekdayNames[1] = "Tuesday";
    weekdayNames[2] = "Wednesday";
    weekdayNames[3] = "Thursday";
    weekdayNames[4] = "Friday";
    weekdayNames[5] = "Saturday";
    weekdayNames[6] = "Sunday";

    int totalSundays = 0;
    int month = 1;
    int day = 1;

    // Time machine
    for(int year = 1901; year < 2001;)
    {
        int totalDays = day;

        for(int y = 1900; y <= year; y++)
        {
            int tempMonth = (y == year) ? (month-1) : 12;

            if(y == year)
                int b = 0;

            for(int m = 0; m < tempMonth; m++)
            {
                if(LeapYear(y))
                    daysInMonth[1] = 29;
                else
                    daysInMonth[1] = 28;

                totalDays += daysInMonth[m];
            }
        }

        string weekDay = weekdayNames[(totalDays-1) % 7];

        if(weekDay == "Sunday")
        {
            cout << weekDay << " -- " << month << "--" << year << endl;
            totalSundays++;
        }

        month++;

        if(month > 12)
        {
            year++;
            month = 1;
        }
    }

    mAnswer << totalSundays; 
}

bool Problem19::LeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
    {
        return true;
    }

    return false;
}


}// namespace
