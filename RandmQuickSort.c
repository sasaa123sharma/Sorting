//Randomized quick sort
//
//Complexity always O(nlogn);
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int QuickPart(int *a, int start, int end)
{
	int pivot = a[end];
	int index = start;
	int i = start;
	
	while(i < end)
	{
		if(a[i] <= pivot)
		{
			int temp = a[i];
			a[i] = a[index];
			a[index] = temp;
			index++;
		}
		i++;
	}
	//exchange a[random] and a[inedx];
	int temp = a[index];
	a[index] = a[end];
	a[end] = temp;

	return index;
}

int RanQuickPart(int *a, int start, int end)
{
	int size = end - start +1;
	
	srand(time(NULL));
	
	int random = rand()%size ;
	random = random  + start; //this will give number between start to end
	
	printf("random = %d\n", random);

	int temp = a[end];
	a[end] = a[random];
	a[random] = temp;

	return QuickPart(a, start, end);
}

void RandmQuickSort(int *a, int start, int end)
{
	if(start < end)
	{
		int iPivot = RanQuickPart(a, start, end);
		RandmQuickSort(a, start, iPivot - 1);
		RandmQuickSort(a, iPivot + 1, end);
	}
	return;
}


int main()
{
	int i =0;
	//int a[] = {9, 8, 1, 3 ,7};
	int a[] = {9, 8, 1, 3 ,7, 4, 2, 0, 5, 6};

	int size = sizeof(a)/sizeof(int);

	RandmQuickSort(a, 0, size -1);	
	
	for( i = 0; i < size ; i++)
		printf("%d  ", a[i]);	

	printf("\n");
	
	return 0;
}
