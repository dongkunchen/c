#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 1;
	int *p = &i;//類型(type)是int* 不是int
	// int *p;
	// p = &i;
	float *q;//都佔64/8 8字節
	double *d;//都佔64/8 8字節
	char *c;//都佔64/8 8字節 
	//但是指針指向的那個存放數據類型要跟指針類型相同
	//如果int聲明成char會只取地址中存放數值1個字節 但是int有4個字節
	

	printf("%d\n", sizeof(i));//四個字節
	//64位元/8 8字節 32位元/8 4字節
	printf("%d\n", sizeof(p));

	printf("i = %d\n", i);
	printf("&i = %p\n", &i);
	printf("p = %p\n", p);
	printf("&p = %p\n", &p);		
	printf("*p = %d\n", *p);

	exit(0);
}
