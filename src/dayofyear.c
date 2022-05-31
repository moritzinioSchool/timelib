#include "dayofyear.h"

//
// Berechnet fuer gegebenes Datum die Nummer des angegebenen Tages
//
int day_of_the_year(struct date _date)
{
    int day_of_year = -1;
    // pruefen ob Tag existiert
    if (exists_date(_date) == 1)
    {
        // Tage der Monate davor
        day_of_year = 0;
        for (int i = 0; i < _date.month -1; i++)
        {
            day_of_year += get_days_for_month(_date);
        }
        // +Tag im aktuellen Monat
        day_of_year += _date.day;

        // +1 Bei Schaltjahr
        if (is_leapyear(_date) == 1 && _date.month > 2)
        {
            day_of_year += 1;
        }
    }
    return day_of_year;
}


//
// Schaltjahresbestimmung
//
int is_leapyear(struct date _date)
{
    int year_is_leapyear = -1;
    if (_date.year >= 1582)
    {
        if (_date.year % 4 == 0)
        {
            if (_date.year % 100 == 0)
            {
                if (_date.year % 400 == 0)
                {
                    // Schaltjahr
                    year_is_leapyear = 1;
                }
                else
                {
                    // kein Schaltjahr
                    year_is_leapyear = 0;
                }
            }
            else
            {
                // Schaltjahr
                year_is_leapyear = 1;
            }
        }
        else
        {
            // kein Schaltjahr
            year_is_leapyear = 0;
        }
    }
    else
    {
        // ungueltiges Jahr
        year_is_leapyear = -1;
    }

    return year_is_leapyear;
}

//
// Bestimmung der Tage des Angegebenen Monats
//
int get_days_for_month(struct date _date) 
{
    int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day_of_the_month = -1;
    if (_date.month > 0 && _date.month < 13)
    {
        if (_date.month == 2 && is_leapyear(_date) == 1)
        {
            // Februar Schaltjahr
            day_of_the_month = days_per_month[_date.month] + 1;
        }
        else 
        {
            // Kein Schaltjahr
            day_of_the_month = days_per_month[_date.month];
        }
    }
    else
    {
        // Ungueltiger Monat
        day_of_the_month = -1;
    }
    return day_of_the_month;
}

//
// Ueberprueft ob angegebenes Datum gueltig ist
//
int exists_date(struct date _date)
{
    int date_exists = 0;
    if (_date.day > 0 && _date.day <= get_days_for_month(_date) 
        && _date.month > 0 && _date.month <= get_days_for_month(_date)
        && _date.year > 1581 && _date.year < 2401)
    {
        date_exists = 1;
    }

    return date_exists;
}