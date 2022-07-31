/*
	Time Complexity: O((N ^ 2) * log(N ^ 2))
	Space Complexity: O(N ^ 2)

	Where 'N' is the number of elements the given arrays.
*/

#include<algorithm>

vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Array to store all the possible sum combinations.
	vector<int>tempArray;
	
	// Loop to traverse the array 'A'.
	for(int i = 0; i < n; i++){
		// Loop to traverse the array 'B'.
		for(int j = 0; j < n; j++){
			int currentSum = a[i] + b[j];
			// Add the sum of current combination .
			tempArray.push_back(currentSum);
		}
	}
	// Sort the array in descending order.
	sort(tempArray.begin(), tempArray.end(), greater<int>()); 
	
	// Return the first 'K' values.
	vector<int> result(tempArray.begin(), tempArray.begin() + k);
	return result;
}