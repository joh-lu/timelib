/**
*   Tag des Jahres berechnen
*   Autor: Johanna
*   Erstellt am: 11.01.2020
**/


#include <stdio.h>
#include <stdlib.h>
#include "lib.h"


struct dateStruct
{
    int day;
    int month;
    int year;
};



int main()
{
    struct dateStruct date;
    int dayofyear = 0;

    date = input_date(date);
    dayofyear = day_of_the_year(date.year, date.month, date.day);

    //Ausgabe
    if(dayofyear > 366)
    {
        printf("Der Tag des Jahres ist zu gross, es konnte keine Berechnung stattfinden!");
    }
    else
    {
        printf("Das eingegebene Datum ist der %i. Tag des Jahres.", dayofyear);
    }
}
