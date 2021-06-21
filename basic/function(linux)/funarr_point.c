#include <stdio.h>
#include <stdlib.h>

int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a-b;
}

int main()
{
    int a = 4, b = 3;
    int ret,i;
    int (*funp[2])(int,int);//函數指針數組:一個數組裡面是函數指針
    funp[0] = sum;
   funp[1] = sub;

   for ( i = 0; i < 2; i++)
   {
       ret = funp[i](a,b);
       printf("%d\n",ret);
   }
 
    return 0;
}