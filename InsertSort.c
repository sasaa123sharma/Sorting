//In Place
//complexity 
//Best case - O(n) -- When array is already sorted
//worst and avg case - O(n2)
//stable algo
//Though the complexity is O(n2) but in practical scenarios no of comparisons are less than the bubble and inserion 
//So it is better than insertion and bubble sort


#include <stdio.h>
#include <stdlib.h>

void InsertSort(int *a, int size)
{
	int i = 0, j =0;
	int value ;
	
	for(i = 1; i < size; i++)
	{
		value = a[i];
		j = i;
		while(value < a[j-1] && j > 0)
		{
			a[j] = a[j-1];
			j--;
		}
		a[j] = value;	
	} 
	return;
}

int main()
{
	int i = 0;
	int size = 0;
	//int a[] = { 9,1,5,3,4};
	int a[] = { 1,3,4,5,9};
	size = sizeof(a)/sizeof(int);
	
	InsertSort(a, size);
	for(i = 0; i < size ;i++)
		printf("%d  ", a[i]);

	printf("\n");
	return 0;
}
