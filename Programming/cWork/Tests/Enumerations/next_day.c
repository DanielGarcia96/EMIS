#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum day {sun, mon, tue, wed, thu, fri, sat};
typedef enum day    day;

day find_next_day(day d);
char *decipherDay(day d);

int main(void)
{
    day d = sun;

    char *dayString = decipherDay(d);
    printf("Today is %s\n", dayString);
    free(dayString);

    char *dayStringTwo = decipherDay(find_next_day(d));
    printf("Tomorrow is %s\n", dayStringTwo);
    free(dayStringTwo);

    return 0;
}

day find_next_day(day d)
{
    day next_day;

    switch (d)  {
        case sun:
            next_day = mon;
            break;
        case mon:
            next_day = tue;
            break;
        case tue:
            next_day = wed;
            break;
        case wed:
            next_day = thu;
            break;
        case thu:
            next_day = fri;
            break;
        case fri:
            next_day = sat;
            break;
        default:
            next_day = sun;
    } 

    return next_day;
}

char * decipherDay(day d)
{
    char *dayString = (char*) malloc(sizeof(char)*11);
    switch (d)  {
        case sun:
            strcpy(dayString, "Sunday");
            break;
        case mon:
            strcpy(dayString, "Monday");
            break;
        case tue:
            strcpy(dayString, "Tuesday");
            break;
        case wed:
            strcpy(dayString, "Wednesday");
            break;
        case thu:
            strcpy(dayString, "Thursday");
            break;
        case fri:
            strcpy(dayString, "Friday");
            break;
        default:
            strcpy(dayString, "Saturday");
    }

    return dayString;
}
