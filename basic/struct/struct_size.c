#include <stdio.h>
#include <stdlib.h>

// struct size_st
// {
//     char c;
//     int i;
//     float f;
// };

struct size_st
{
    char c;
    int i;
    float f;
}__attribute__((packed));

int main()
{
    struct size_st s = {'s',111,222.444};

    printf("%c %d %f\n",s.c,s.i,s.f);
    // printf("sizeof(s) = %d\n", sizeof(s));//12bytes
    // __attribute__((packed))
    printf("sizeof(s) = %d\n", sizeof(s));//9bytes

    struct size_st *p = &s;

    p->c = 't';
    p->i = 222;
    p->f = 555.777;

    printf("%c %d %f\n",p->c,p->i,p->f);
    printf("sizeof(p) = %d\n", sizeof(p));//8bytes

    return 0;
}