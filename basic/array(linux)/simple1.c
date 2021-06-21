#include <stdio.h>
#include <stdlib.h>

#define M 3

int main()
{
	int i;
	int arr[M];

	printf("%d\n",sizeof(arr));

	for(i = 0 ; i < M; i++)
		scanf("%d", &arr[i]);	

	for(i = 0 ; i < M ; i++)
		printf("%p --> %d\n",&arr[i],arr[i]);

	exit(0);
}
