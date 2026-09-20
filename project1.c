//---GENARATE CALENDER---

#include <stdio.h>
int isLeapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}
int getDaysInMonth(int month, int year)
{
    switch (month)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}
int getStartDay(int month, int year)
{
    if (month < 3) 
    {
        month += 12;
        year--;
    }
    int k = year % 100;
    int j = year / 100;
    int h = (1 + (13 * (month + 1)) / 5 + k + (k / 4) + (j / 4) + 5 * j) % 7;
    return (h + 6) % 7;
}

void printMonthCalendar(int month, int year)
{
    const char *months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };

    int days = getDaysInMonth(month, year);
    int startDay = getStartDay(month, year);

    printf("\n\n  ------------%s %d------------\n", months[month - 1], year);
    printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

    for (int i = 0; i < startDay; i++)
    {
        printf("     ");
    }
    for (int day = 1; day <= days; day++)
    {
        printf("%5d", day);
        if ((startDay + day) % 7 == 0)
            printf("\n");
    }
    printf("\n");
}

int main()
{
    int year;
    printf("Enter the year: ");
    scanf("%d", &year);
    if (year < 1)
    {
        printf("Invalid year!\n");
        return 1;
    }
    for (int month = 1; month <= 12; month++)
    {
        printMonthCalendar(month, year);
    }

    return 0;
}



