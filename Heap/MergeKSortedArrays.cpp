/*
    Time Complexity: O((N * K) * log(N * K))
    Space Complexity: O(N * K)
    
    Where K is the number of arrays and N is the average number of elements in every array.
*/

#include<algorithm>

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Output array.
    vector<int> result;
    
    // Traverse all the k vectors.
    for(int i = 0;i < k; i++)
    {
        for(int j = 0; j < kArrays[i].size(); j++)
        {
            // Add the element to the output array.
            result.push_back(kArrays[i][j]);
        }
    }
    
    // Sort the output array.
    sort(result.begin(), result.end());
    
    return result;
}
