/*
	Time Complexity: O(N * log(N))
	Space Complexity: O(1)

	where 'N' is the size of the array.
*/

int kthLargest(vector<int>& arr, int size, int K)
{
	sort(arr.begin(), arr.end(), greater<int>());
	return arr[K - 1];
}