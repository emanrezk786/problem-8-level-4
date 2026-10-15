#include <iostream>

using namespace std;

bool IsLeapYear(short Year)
{

    return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 == 0);

}

short DayOfWeekOrder(short Day, short Month, short Year)
{
    short A, Y, M;

    A = (14 - Month) / 12;

    Y = Year - A;

    M = Month + (12 * A) - 2;

    return (Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

}

string DayShortName(short DayOfWeekOrder)
{
    string ArrDayNames[] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , "Fri" , "Sat" };

    return ArrDayNames[DayOfWeekOrder];
}

short NumberOfDaysInMonth(short Month, short Year)
{
    if (Month < 1 || Month > 12)
        return 0;


    int NumberOfDays[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 31 , 31 , 30 , 31 , 30 , 31 };

    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : NumberOfDays[Month - 1];

}

string  MonthShortName(short Month)
{
    string Months[12] = { "Jan" , "Feb" , "Mar" , "Apr" , "May" , "Jun" , "Jul"  , "Aug" , "Sep" , "Oct" , "Nov" , "Dec" };

    return (Months[Month - 1]);
}

void PrintMonthCalender(short Month , short Year)
{
    int NumberOfDays;

    int Current = DayOfWeekOrder(1, Month, Year);

    NumberOfDays = NumberOfDaysInMonth(Month, Year);

    printf("\n  __________________%s__________________\n\n",
        MonthShortName(Month).c_str());

    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    int i;
    for (i = 0; i < Current; i++)
        printf("     ");

    for (int j = 1; j <= NumberOfDays; j++)
    {
        printf("%5d" , j);

        if (++i == 7)
        {
            i = 0;
            printf("\n");
        }
    }
    
    printf("\n  ______________________________________\n\n");


}

short ReadMonth()
{
    short Month;
    cout << "\n Please Enter a Month ?";
    cin >> Month;
    return Month;
}

short ReadYear()
{
    short Year;
    cout << "\n Please Enter a Year ?";
    cin >> Year;
    return Year;
}

int main()
{
    short Year = ReadYear();
    short Month = ReadMonth();

    PrintMonthCalender(Month, Year);

    return 0;
}

