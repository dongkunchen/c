#include <stdio.h>
#include <stdlib.h>

#define N 3

int main()
{
	int i;
	int arr[N];

	printf("%d\n",sizeof(arr));

	for(i = 0 ; i < N; i++)
		scanf("%d", &arr[i]);	

	for(i = 0 ; i < N ; i++)
		printf("%p --> %d\n",&arr[i],arr[i]);

	exit(0);
}
