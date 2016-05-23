//stable algo
//inplace
//complexity 
//best case- O(n) if array is already sorted(after doing some manipulations else O(n2))
//worst and avg case - O(n2)

#include   <stdio.h>
#include<stdlib.h>

void BubbleSort(int *a, int size)
{	
	int i = 0, j = 0;
	int flag = 0, temp = 0;
	
	//for(i = 0; i < size ;i++)
	for(i = 0; i < size -1 ;i++)//you will be sorted after n-2 loops in worst case
	{
		flag = 0;
		for(j = 0; j < size -1 -i; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		}	
		//if flag is 0 after any loop means array is sorted now 
		//so we can bail out from here
		if(!flag)
			break; 
	}
	return ;
}

int main()
{
	int i = 0, size = 0;
	//int a[] = {9,5,1,6,7};
	int a[] = {1,2,3,4,5};
	size = sizeof(a)/sizeof(int);
	BubbleSort(a, size);

	for(i = 0; i < size ; i++)
		printf("%d  ", a[i]);

	printf("\n");
	return 0;
}
