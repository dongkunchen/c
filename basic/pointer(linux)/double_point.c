#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 1;
	int *p = &i;//類型(type)是int* 不是int
    int **q = &p;

	printf("%d\n", sizeof(i));//四個字節
	//64位元/8 8字節 32位元/8 4字節
	printf("%d\n", sizeof(p));

	//i的值可以 *p **p
	//&i的地址可以 p *p
	printf("i = %d\n", i);
	printf("&i = %p\n", &i);

	printf("p = %p\n", p);
	printf("&p = %p\n", &p);		
	printf("*p = %d\n", *p);

    printf("q = %p\n", q);//p地址
    printf("&q = %p\n", &q);//q地址
    printf("*q = %p\n", *q);//i地址
    printf("**q = %d\n", **q);//i的值

	exit(0);
}
