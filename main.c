/**
*   Tag des Jahres berechnen
*   Autor: Johanna
*   Erstellt am: 11.01.2020
**/


#include <stdio.h>
#include <stdlib.h>


struct dateStruct
{
    int day;
    int month;
    int year;
};

int is_leapyear(int year)
{
    //Prüfung, ob das eingegebene JAhr ein Schaltjahr ist
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

    if (year < 1582)
    {
        return -1;
    }
}

int exists_date(int day, int month, int year)
{
    if ((day < 1) && (month < 1) && (year < 1582) || (day > 31) && (month > 12) && (year > 2400))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int day_of_the_year(int dayoftheyear, int day)
{
    return dayoftheyear + day;
}


int main()
{
    int i;
    struct dateStruct date;
    int dayofyear = 0;
    int leapyear;
    int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};


    //Eingabeauforderung des Jahres und löschen des Tastaturpuffers
    printf("Bitte geben Sie das Jahr ein. ");
    scanf("%i", &date.year);
    fflush(stdin);

    //Eingabeauforderung des Jahres und löschen des Tastaturpuffers
    printf("\nBitte geben Sie den Monat ein. ");
    scanf("%i", &date.month);
    fflush(stdin);

    //Eingabeauforderung des Jahres und löschen des Tastaturpuffers
    printf("\nBitte geben Sie den Tag ein. ");
    scanf("%i", &date.day);
    fflush(stdin);

    //Prüfen, ob das Datum existiert
    if(exists_date(date.day, date.month, date.year) == 1)
    {
        printf("\nDatum zu gross oder zu klein!");
    }
    else
    {
        printf("\nDatum korrekt eingegeben. Berechnung des Tages gestartet.");
    }

    //Berechnung des Tages im Jahr
    for (i = 0; i < date.month - 1; i ++)
    {
       dayofyear = dayofyear + days_per_month[i];
       //printf("%i", days_per_month[i]);
    }

    //Addieren der angegebenen Tage
    day_of_the_year(dayofyear, date.day);

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
