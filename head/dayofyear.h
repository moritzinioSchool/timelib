#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

struct date
{
    int year;
    int month;
    int day;
};

// Funktionen
int day_of_the_year(struct date _date);
int is_leapyear(struct date _date);
int get_days_for_month(struct date _date);
int exists_date(struct date _date);

#endif