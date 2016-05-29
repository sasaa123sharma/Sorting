//Divide and Conquer
//Inplace
//recursive
//Its not stable algo

#include <stdio.h>
#include <stdlib.h>

int QuickPart(int *a, int start, int end)
{
	int iIndex = start;
	int i = start;
	int pivot = a[end];
	
	for(; i < end; i++)
	{
		if(a[i] <= pivot)//then swap a[i] with a[iIndex]
		{
			int temp = a[i];
			a[i] = a[iIndex] ;
			a[iIndex] = temp;  	
			iIndex++;
		}	
	}	  

	//finally swap the pivot and iIndex element
	int temp = pivot;
	a[end] = a[iIndex];
	a[iIndex] = temp;
	
	//for(i = 0; i < 8 ; i++)
	//	printf("%d  ", a[i]);
	//printf("\n\n");
	return iIndex;
}

//QuickSort
void QuickSort(int *a, int start, int end)
{
	//start < end condition will deal with invalid indexes as well as subarray of single element
	if(start < end)
	{
		int p = QuickPart(a, start, end);
		QuickSort(a, start, p -1);
		QuickSort(a, p+1, end);
	}
	return ;
}

int main()
{
	//int a[] = {7,2,1,6,8,5,3,4};
	int a[] = {-7,-2,-1,-6,-8,-5,-3,-4};
	
	int size = sizeof(a)/sizeof(int);
	QuickSort(a, 0, size -1);	
	
	int i = 0;
	for(i = 0; i < size ; i++)
		printf("%d  ", a[i]);
	
	printf("\n");
	return 0;
}
