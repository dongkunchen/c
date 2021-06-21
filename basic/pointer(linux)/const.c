#include <stdio.h>
#include <stdlib.h>

int main()
{
    // //常量指針(可以改變指針指向不能改變指向地址內容值)
    // int i = 1;
    // int j = 100;
    // const int *p = &i;
    // i = 10;
    // p = &j;
    // // *p = 10;//error
    // printf("%d\n", *p);

    // //指針常量(不能改變指針指向可以改變指向地址內容值)
    // int i = 1;
    // int j = 100;
    // int *const p = &i;
    // i = 10;
    // // p = &j;//error
    // *p = 10;
    // printf("%d\n", *p);

    int i = 1;
    int j = 100;
    const int *const p = &i;
    // p = &j;//error
    // *p = 10;//error

    printf("%d\n", *p);

    // const float pi = 3.14;
    // // pi = 3.14159; const 只能讀不能再賦值 報錯
    // // 可用下面來修改但是會警告
    // float *p = &pi;
    // *p = 3.14159;

    // printf("%f\n", pi);

    exit(0);
}