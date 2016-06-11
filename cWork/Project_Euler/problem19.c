#include <stdio.h>

enum days {
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday,
    sunday
};

void printDay(enum days d);
enum days progressDay(enum days d);

int main(void)
{
    int i, count = 0;
    enum days d = monday;

    for(i=1; i <= 31; i++)
        d = progressDay(d);
    for(i=1; i <= 28; i++)
        d = progressDay(d);
    for(i=1; i <= 31; i++)
        d = progressDay(d);
    for(i=1; i <= 30; i++)
        d = progressDay(d);
    for(i=1; i <= 31; i++)
        d = progressDay(d);
    for(i=1; i <= 30; i++)
        d = progressDay(d);
    for(i=1; i <= 31; i++)
        d = progressDay(d);
    for(i=1; i <= 31; i++)
        d = progressDay(d);
    for(i=1; i <= 30; i++)
        d = progressDay(d);
    for(i=1; i <= 31; i++)
        d = progressDay(d);
    for(i=1; i <= 30; i++)
        d = progressDay(d);
    for(i=1; i <= 31; i++)
        d = progressDay(d);
    
    for(i=1901; i<=2000; i++)
    {
        int j;
        for(j=1; j <= 31; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }

        int length = (i % 4 == 0) ? 29 : 28;
        for(j=1; j <= length; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 31; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 30; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 31; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 30; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 31; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 31; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 30; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 31; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 30; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
        for(j=1; j <= 31; j++)
        {
            if(j == 1 && d == sunday)
                count++;
            d = progressDay(d);
        }
    }

    printf("%d\n", count);
    return 0;
}

enum days progressDay(enum days d)
{
    switch(d)
    {
        case monday:
            return tuesday;
        case tuesday:
            return wednesday;
        case wednesday:
            return thursday;
        case thursday:
            return friday;
        case friday:
            return saturday;
        case saturday:
            return sunday;
        default:
            return monday;
    }
}

void printDay(enum days d)
{
    switch(d)
    {
        case monday:
            printf("monday\n");
        break;
        case tuesday:
            printf("tuesday\n");
        break;
        case wednesday:
            printf("wednesday\n");
        break;
        case thursday:
            printf("thursday\n");
        break;
        case friday:
            printf("friday\n");
        break;
        case saturday:
            printf("saturday\n");
        break;
        default:
            printf("sunday\n");
    }
}
