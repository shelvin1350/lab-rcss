#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i;
	int count;
	int *arr;
	int sum;
	int avg;
	
	printf("Enter the number of elements: ");
	scanf("%d", &count);
	
	arr=(int *)malloc(count * sizeof(int));
	
	for(i=0; i<count; i++)
	{
		printf("Enter the element: ");
		scanf("%d", arr+i);
		
		sum=sum + *(arr+i);
	}
	avg = sum/count;
	
	printf("Average = %d", avg);
	return 0;
}
