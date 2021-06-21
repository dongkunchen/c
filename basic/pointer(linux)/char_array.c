//字符陣列跟指針關係
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char *str1 = "hello";//hello is string constant;
    printf("%d %d\n",sizeof(str1),strlen(str1));// 8 5
    //strcpy(str1,"world");//error: str1 is pointer char(constant);
    str1 = "world"; //str1 is adress variable;
    puts(str1);
    
    // char str[] = "hello world";
    char str[] = "hello";
    printf("%d %d\n",sizeof(str),strlen(str));// 6 5
    //str = "world";//error: str is adress constant;
    strcpy(str,"world");
    puts(str);

    char str2[] = "hello world";
    char *p = str2+6;
    puts(p);

    exit(0);
}