#include <stdio.h>
#include <stdlib.h>

#define NAMESIZE 32
#define SEXSIZE 10
#define CLASS_NAMESIZE 10

// struct student_st
// {
//     int s_id;
//     char name[NAMESIZE];
//     int s_age;
//     char classname[CLASS_NAMESIZE];
// };

// struct teacher_st
// {
//     int t_id;
//     char name[NAMESIZE];
//     int t_age;
//     char sex[SEXSIZE];
//     struct student_st stu;
// };

struct teacher_st
{
    int t_id;
    char name[NAMESIZE];
    int t_age;
    char sex[SEXSIZE];
    struct student_st
    {
        int s_id;
        char name[NAMESIZE];
        int s_age;
        char classname[CLASS_NAMESIZE];
    }stu;
};

int main()
{
    
    return 0;
}