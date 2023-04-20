#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int d, m, y;
}Date;

int sameDay(Date, Date);
void input(Date *, Date *);

int main()
{
    Date day1, day2;
    /*
    printf("Enter day 1 (dd-mm-yyyy) : ");
    scanf("%d %d %d", &day1.d, &day1.m, &day1.y);
    printf("Enter day 2 (dd-mm-yyyy) : ");
    scanf("%d %d %d", &day2.d, &day2.m, &day2.y);
    */
    //I can use the code above but let's try using pointer ;)
    input(&day1, &day2);

    if(sameDay(day1, day2))
        printf("It is the same day\n");
    else
        printf("It's not the same day\n");

}

void input(Date *day1, Date *day2)
{
    //int d1, d2, m1, m2, y1, y2;
    printf("Enter day 1 (dd-mm-yyyy) : ");
    scanf("%d %d %d", &(*day1).d, &(*day1).m, &(*day1).y);
    printf("Enter day 2 (dd-mm-yyyy) : ");
    scanf("%d %d %d", &day2->d, &day2->m, &day2->y);

}

int sameDay(Date day1, Date day2)
{
    if(day1.d == day2.d && day1.m == day2.m)
        if(day1.y == day2.y)
            return 1;
        else
            return 0;
    else
        return 0;
}

//0 equal false
