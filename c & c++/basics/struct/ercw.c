#include<stdio.h>
#include<stdlib.h>

int main(){
    struct Student {
        const char *name;
        const char *id;
        int entrance_year;
        int dorm;
        };

    struct Student stu;
    stu.name = "Sunny";
    stu.id = "12345";
    stu.entrance_year = 2018;
    stu.dorm = 1;

    printf("Name: %s\n", stu.name);
    printf("ID: %s\n", stu.id);
    printf("Entrance Year: %d\n", stu.entrance_year);
    printf("Dorm: %d\n", stu.dorm);
    
    struct Student s1 = {"Sunny", "12345", 2018, 1};
    printf("Name: %s\n", s1.name);
    printf("ID: %s\n", s1.id);
    printf("Entrance Year: %d\n", s1.entrance_year);
    printf("Dorm: %d\n", s1.dorm);


    struct Student *pStu = malloc(sizeof(struct Student));
    pStu->name = "Sunny";
    pStu->id = "12345";
    pStu->entrance_year = 2018;
    pStu->dorm = 1;

    
    printf("%d\n", pStu->entrance_year);
    puts(pStu->name);
    printf("%s\n", pStu->name);
    free(pStu);
    printf("%zu\n", sizeof(struct Student));
    printf("%s\n",s1.name);
    return 0;
}