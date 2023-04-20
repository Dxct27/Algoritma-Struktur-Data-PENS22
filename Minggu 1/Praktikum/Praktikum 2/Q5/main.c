#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int d, m, y;
}Date;

typedef struct{
    char name[60];
    double averageScore;
    Date dob; //date of birth
}Student;

int isYounger(Student, Student);
void input(Student *, Student *);

int main()
{
    Student stud1, stud2;

    input(&stud1, &stud2);

    if(isYounger(stud1, stud2))
        printf("%s is Younger than %s", stud1.name, stud2.name);
    else
        printf("%s is Younger than %s", stud2.name, stud1.name);
}

void input(Student *stud1, Student *stud2)
{
    int d1, d2, m1, m2, y1, y2;
    printf("Name\t\t : ");
    scanf("%s", stud1->name);
    //fflush(stdin);
    printf("DoB(dd mm yyyy)\t : ");
    scanf("%d %d %d", &d1, &m1, &y1);
    stud1->dob.d = d1;
    stud1->dob.m = m1;
    stud1->dob.y = y1;

    printf("\nName\t\t : ");
    scanf("%s", stud2->name);
    //fflush(stdin);
    printf("DoB(dd mm yyyy)\t : ");
    scanf("%d %d %d", &d2, &m2, &y2);
    stud2->dob.d = d2;
    stud2->dob.m = m2;
    stud2->dob.y = y2;
}

int isYounger(Student stud1, Student stud2)
{
    if(stud1.dob.y >= stud2.dob.y){
        if(stud1.dob.m >= stud2.dob.m){
            if(stud1.dob.d > stud2.dob.d)
            return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
        return 0;

}
