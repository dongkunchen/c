#include <stdio.h>
#include <stdlib.h>

union test_un
{
    int i;
    float f;
    double d;
    char c;
};


int main()
{
    union test_un a;
    union test_un *p = &a;
    union test_un arr[3];

    // a.f = 123.222;
    p->i = 123;
    
    
    printf("%d\n",sizeof(a));
    printf("%d\n",sizeof(p));
    // printf("%f\n",a.f);
    printf("%d\n",p->i);
    

    return 0;
}