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
    int ret,ret1;
    int (*p)(int, int);//函數指針---定義指針內容指向函數
    int (*p1)(int, int);

    p = sum;
    p1 = sub;
    ret = p(a, b);
    ret1 = p1(a,b);
    printf("%d\n", ret);
    printf("%d\n", ret1);

    return 0;
}