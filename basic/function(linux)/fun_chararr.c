#include <stdio.h>
#include <stdlib.h>

char *mystrcpy(char *dest, const char *src)
{
    char *ret = dest;
    if (dest != NULL && src != NULL)
        while ((*dest++ = *src++) != '\0');

    return ret;
}

char *mystrncpy(char *dest, const char *src, size_t n)
{
    int i;
    for ( i = 0; i < n && (dest[i]=src[i]); i++);
    for (; i < n+1; i++)
        dest[i] = '\0';
    return dest;
    
}

int main()
{

    char str1[] = "hellolinux";
    char str2[1024];
    int n = 5;

    // mystrcpy(str2, str1);
    mystrncpy(str2, str1, n);

    puts(str2);

    return 0;
}