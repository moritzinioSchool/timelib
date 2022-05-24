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
    int year = 0;
    int month = 0;
    int day = 0;

    //
    // Einlesen
    //
    printf("Geben Sie das Jahr ein: ");
    scanf("%i", &year);
    printf("Geben Sie den Monat ein: ");
    scanf("%i", &month);
    printf("Geben Sie den Tag ein: ");
    scanf("%i", &day);

    //
    // Ausgabe
    //
    printf("\nEs ist der %i Tag des Jahres!\n", day_of_the_year);

}