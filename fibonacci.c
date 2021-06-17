#include <stdio.h>
#include <stdlib.h>

static void fibonacci(void)
{
	int i,j,tmp;
	int fib[10] = {1,1};
	
	for(i = 2; i < sizeof(fib)/sizeof(fib[0]); i++)
		fib[i] = fib[i-1] + fib[i-2];
	for(i = 0; i < sizeof(fib)/sizeof(fib[0]); i++)
		printf("%d ",fib[i]);
	printf("\n"); 

	i = 0;
	j = sizeof(fib)/sizeof(fib[0]) - 1;

	while(i<j)
	{
		tmp = fib[i];
		fib[i] = fib[j];
		fib[j] = tmp;
		
		i++;
		j--;
	}
 		
	for(i = 0; i < sizeof(fib)/sizeof(fib[0]); i++)
		printf("%d ",fib[i]);
	printf("\n");	

	return;
}

int main()
{

	fibonacci();

		

}
