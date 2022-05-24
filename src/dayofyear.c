#include "dayofyear.h"

//
// Berechnet fuer gegebenes Datum die Nummer des angegebenen Tages
//
int day_of_the_year(int _day, int _month, int _year)
{
    int day_of_year = -1;
    // pruefen ob Tag existiert
    if (exists_date(_day, _month, _year) == 1)
    {
        // Tage der Monate davor
        day_of_year = 0;
        for (int i = 0; i < _month -1; i++)
        {
            day_of_year += get_days_for_month(_month, _year);
        }
        // +Tag im aktuellen Monat
        day_of_year += _day;

        // +1 Bei Schaltjahr
        if (is_leapyear(_year) == 1 && _month > 2)
        {
            day_of_year += 1;
        }
    }
    return day_of_year;
}


//
// Schaltjahresbestimmung
//
int is_leapyear(int _year)
{
    int year_is_leapyear = -1;
    if (_year >= 1582)
    {
        if (_year % 4 == 0)
        {
            if (_year % 100 == 0)
            {
                if (_year % 400 == 0)
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
int get_days_for_month(int _month, int _year) 
{
    int days_per_month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int day_of_the_month = -1;
    if (_month > 0 && _month < 13)
    {
        if (_month == 2 && is_leapyear(_year) == 1)
        {
            // Februar Schaltjahr
            day_of_the_month = days_per_month[_month] + 1;
        }
        else 
        {
            // Kein Schaltjahr
            day_of_the_month = days_per_month[_month];
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
int exists_date(int _day, int _month, int _year)
{
    int date_exists = 0;
    if (_day > 0 && _day <= get_days_for_month(_month, _year) 
        && _month > 0 && _month <= get_days_for_month(_month, _year)
        && _year > 1581 && _year < 2401)
    {
        date_exists = 1;
    }

    return date_exists;
}