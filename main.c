/**
*   Tag des Jahres berechnen
*   Autor: Johanna
*   Erstellt am: 11.01.2020
**/


#include <stdio.h>
#include <stdlib.h>

int is_leapyear(int year)
{
    //Pr�fung, ob das eingegebene JAhr ein Schaltjahr ist
    //Jahr ohne Rest durch 4 teilbar?
    if (year%4 == 0)
    {
         // Jahr ohne Rest durch 100 teilbar?
        if (year%100 == 0)
        {
            //Jahr ohne Rest durch 400 teilbar?
            if(year%400 == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
          return 1;
        }
    }
    else
    {
        return 0;
    }
}

int main()
{
    int i;
    int year = 0;
    int month = 0;
    int day = 0;
    int dayofyear = 0;
    int leapyear;
    int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    //Eingabeauforderung des Jahres und l�schen des Tastaturpuffers
    printf("Bitte geben Sie das Jahr ein. ");
    scanf("%i", &year);
    fflush(stdin);

    //setzten der Tage im Februar auf 29, wenn das eingegebene Jahr ein Schaltjahr ist
    if (is_leapyear(year) == 1)
    {
        days_per_month[1] = 29;
    }

    //Eingabeauforderung des Jahres und l�schen des Tastaturpuffers
    printf("\nBitte geben Sie den Monat ein. ");
    scanf("%i", &month);
    fflush(stdin);

    //Eingabeauforderung des Jahres und l�schen des Tastaturpuffers
    printf("\nBitte geben Sie den Tag ein. ");
    scanf("%i", &day);
    fflush(stdin);

    //Berechnung des Tages im Jahr
    for (i = 0; i < month - 1; i ++)
    {
       dayofyear = dayofyear + days_per_month[i];
       //printf("%i", days_per_month[i]);
    }

    //Addieren der angegebenen Tage
    dayofyear = dayofyear + day;

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
