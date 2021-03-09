#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED


int is_leapyear(int year);
int exists_date(int day, int month, int year);
int get_days_per_month(int month, int year);
int day_of_the_year(int year, int month, int day);
struct dateStruct input_date(struct dateStruct date);

#endif // LIB_H_INCLUDED
