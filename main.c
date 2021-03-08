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

struct dateStruct input_date(struct dateStruct date)
{
    do
    {
        //Eingabeauforderung des Jahres und löschen des Tastaturpuffers
        printf("\nBitte geben Sie das Jahr ein. ");
        scanf("%i", &date.year);

        //Eingabeauforderung des Jahres und löschen des Tastaturpuffers
        printf("\nBitte geben Sie den Monat ein. ");
        scanf("%i", &date.month);

        //Eingabeauforderung des Jahres und löschen des Tastaturpuffers
        printf("\nBitte geben Sie den Tag ein. ");
        scanf("%i", &date.day);

        //Prüfen, ob das Datum existiert
        if(exists_date(date.day, date.month, date.year) == 0)
        {
            printf("\nDatum zu gross oder zu klein!");
        }
        else
         {
             printf("\nDatum korrekt eingegeben. Berechnung des Tages gestartet.\n");
         }


    }
    while(exists_date(date.day, date.month, date.year) == 0);


    return date;
}

int main()
{
    struct dateStruct date;
    int dayofyear = 0;

    date = input_date(date);
    dayofyear = day_of_the_year(date.year, date.month, date.day);

    //Ausgabe
    if(dayofyear > 366)
    {
        printf("Der Tag des Jahres ist zu gross, es konnte keine Berechnung statfinden!");
    }
    else
    {
        printf("Das eingegebene Datum ist der %i. Tag des Jahres.", dayofyear);
    }
}
