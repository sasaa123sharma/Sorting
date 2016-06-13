//Counting sort
//
//This technique is based on keys between specific range
//Here we do some arithmetic calculations to calculate the position of each element
//
//Idea - 
//Take a count array equal to of size of range of numbers to be sorted
//calculate the count of each unique object and put it in to the count array against the element
//whatever element is not present put count 0 in  the count array
//now in count array add the count of previous element(except in case of first element) and update the count array
//no take one output array of size of original array, put the element of original array in this output array as number
//indicated in the count array and decrease count by 1 of each element in count array.
//
//Time Complexity: O(n+k) where n is the number of elements in input array and k is the range of input.
//Auxiliary Space: O(n+k)

//Implementation -- 

#include <stdio.h>
#include <stdlib.h>  
#include <string.h>  

void CountSort(char *arr, int size, int range)
{
	char output[size];
	char count[range+1]; //as 0 to 127

	int i = 0;
	memset(count, 0x00, sizeof(count));

	//for(i = 0; i <= range ; i++)
	//count[i] = 0;

	//Count the occurrence of each element 
	for(i = 0; i < size ; i++)
		++count[arr[i]];

	//Modify the count array 
	//add count of previous element to the current element count except the first element
	for(i = 1; i <= range ; i++)
		count[i] += count[i-1]; 

	//Fill the output array with sorted element at its position according to the count array
	for(i = 0; i < size ; i++)
	{
		output[count[arr[i]] - 1] = arr[i];//as we are starting from position 0
		count[arr[i]]--;
	}
		
	for(i = 0; i < size ; i++)
		arr[i] = output[i];
	
	return;
}

int main()
{
	char arr[] = "geeksforgeeks";
	int size = sizeof(arr)/sizeof(char);
	int range = 127;//as we have characters as input
	
	CountSort(arr, size, range);

	int i = 0;
	for(i = 0; i < size ;i++)
		printf("%c", arr[i]);
	
	printf("\n");
	return 0;
}
