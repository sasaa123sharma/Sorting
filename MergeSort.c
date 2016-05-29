//Divide and conquer
//Stable algo
//Recursive algo
//Complexity - O(nlogn) - for best average and worst case
//space complexity - O(n)
//
#include <stdio.h>
#include <stdlib.h>

void Merge(int *a, int start, int mid, int end)
{
	
	int i, j , k;
	int nL = mid - start +1; //length of left array
	int nR = end - mid; // length of right array, no need to do +1 as we need to take from mid+1 
	
	int arrL[nL];
	int arrR[nR];

	for(i = 0; i  < nL; i++)
		arrL[i] = a[start+i];
	
	for(i = 0; i  < nR; i++)
		arrR[i] = a[ mid + 1 +i];//+1 as we need to take right array from (mid+1)th element

	i = 0; 
	j = 0;
	k = start;	

	while( i < nL && j < nR)
	{
		if(arrL[i] <= arrR[j])
		{
			a[k] = arrL[i]; 
			k++;
			i++;
		}
		else
		{
			a[k] = arrR[j]; 
			k++;
			j++;
		}
	}
	
	while(i < nL)
	{
		a[k] = arrL[i];
		i++;
		k++;
	}

	while(j < nR)
	{
		a[k] = arrR[j];
		j++;
		k++;
	}
	return;
}


void MergeSort(int *a, int start, int end)
{
	if(start < end )
	{
		int mid = start + (end - start)/2;
		MergeSort(a, start, mid);
		MergeSort(a, mid+1, end);
		//finally merge
		Merge(a, start, mid, end);
	}
	return;
}

int main()
{
	int i  = 0;
	//int a[] = {9, 8, 3, 1, 6};
	//int a[] = {9, 8, 3, 1, 6, 7};
	//int a[] = {9};
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	
	int size = sizeof(a)/sizeof(int);

	printf("Input Array\n");
	for(i = 0; i < size ; i++)
		printf("%d  ", a[i]);
	printf("\n");

	MergeSort(a, 0, size -1);

	printf("Output Array\n");
	for(i = 0; i < size ; i++)
		printf("%d  ", a[i]);

	printf("\n");

	return 0;
}

