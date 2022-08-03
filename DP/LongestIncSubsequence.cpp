/*
    Time Complexity : O(2 ^ N)
    Space Complexity : O(N)
    Where N is the size of the array
*/

#include <climits>

int longestIncreasingSubsequenceHelper(int arr[], int prev, int curPosition, int n)
{
    // Base case
    if (curPosition == n)
    {
        return 0;
    }

    int taken = 0;

    // Taking the current element
    if (arr[curPosition] > prev)
    {
        taken = 1 + longestIncreasingSubsequenceHelper(arr, arr[curPosition], curPosition + 1, n);
    }

    // Not Taking the current element
    int notTaken = longestIncreasingSubsequenceHelper(arr, prev, curPosition + 1, n);

    return max(taken, notTaken);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    return longestIncreasingSubsequenceHelper(arr, INT_MIN, 0, n);
}