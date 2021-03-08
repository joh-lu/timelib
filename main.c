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
    //Prüfen auf richtigkeit des Datums: zwischen 1582 und 2400
    if (((day < 1) || (month < 1) || (year < 1582)) || ((day > 31) || (month > 12) || (year > 2400)) ||
        //Monat und Tag stimmen überein (Monate mit nur 30 statt 31 Tagen)
        ((month == 4) && (day > 30))|| ((month == 6) && (day > 30)) || ((month == 9) && (day > 30)) || ((month == 11) && (day > 30)))
    {
        return 0;
    }
    if (is_leapyear(year) == 1)
    {
        //Februar hat maximal 29 Tage, daher 30 oder 31 nicht möglich
        if ((month == 2) && (day >= 30))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    if (is_leapyear(year) == 0)
    {
        //Februar hat maximal 28 Tage, daher 29, 30 oder 31 nicht möglich
        if ((month == 2) && (day >= 29))
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 1;
    }
}

int get_days_per_month(int month, int year)
{
    int days_per_month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //anpassen der Monate im Februar
    if (is_leapyear(year) == 1)
    {
        days_per_month[1] = 29;
    }
    else if (is_leapyear(year) == 0)
    {
        days_per_month[1] = 28;
    }
    return days_per_month[month - 1];
}


int day_of_the_year(int year, int month, int day)
{
    int i = 0;
    int dayoftheyear = 0;
    //Berechnung des Tages im Jahr
    for (i = 1; i < month; i ++)
    {
        dayoftheyear = dayoftheyear + get_days_per_month(i, year);
    }
    return dayoftheyear + day;
}

struct dateStruct input_date(struct dateStruct date)
{
    do
    {
        //Eingabeauforderung des Jahres und löschen des Tastaturpuffers
        printf("\nBitte geben Sie das Jahr ein. ");
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
        if(exists_date(date.day, date.month, date.year) == 0)
        {
            printf("\nDatum zu gross oder zu klein!");
        }
        /* else
         {
             printf("\nDatum korrekt eingegeben. Berechnung des Tages gestartet.\n");
         }*/


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
