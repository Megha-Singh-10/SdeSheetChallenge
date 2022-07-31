/*
    Time Complexity: O(N * N * log(N))
    Space Complexity: O(1)

    where N is the number of elements in the array.
*/

#include <algorithm>

void findMedian(int arr[], int n)
{
	int median;
	
    // Traverse through the array
	for(int i=0; i<n; i++)
	{	
        // Sort the array from 0-th to i-th index
		sort(arr, arr+i+1);
		
        // Check if i+1 is odd
		if((i+1)%2 == 1)
		{
			median = arr[i/2];
		}
		else
		{
			median = (arr[i/2] + arr[i/2 + 1])/2;
		}	
		
        // Print the variable median
		cout << median << " ";
	}
}

