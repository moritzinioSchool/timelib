/*
 * Konsolenanwendung die angibt, der wievielte Tag im Jahr das eingegebene Datum ist
 *
 * Author: Moritz Hoefelmeyer
 * Datum: 17.05.22
 */

#include <stdio.h>
#include <stdlib.h>
#include "dayofyear.h"

int main()
{
    struct date _date;

    //
    // Einlesen
    //
    printf("Geben Sie das Jahr ein: ");
    scanf("%i", &_date.year);
    printf("Geben Sie den Monat ein: ");
    scanf("%i", &_date.month);
    printf("Geben Sie den Tag ein: ");
    scanf("%i", &_date.day);

    //
    // Ausgabe
    //
    printf("\nEs ist der %i Tag des Jahres!\n", day_of_the_year(_date));

}