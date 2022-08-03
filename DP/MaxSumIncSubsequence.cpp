/* 
    Time Complexity : O(N ^ N)
    Space Complexity : O(N)

     Where N is the number of dumbbells in RACK.
*/


int maxIncreasingDumbbellsSumUtil(vector<int> &rack, int n, int &totalWeight)
{
    // Base case.
    if(n == 0)
    {
        return 0;
    }

    int currWeight = rack[n - 1];

    for(int i = 1 ; i < n ; i++)
    {
        int temp = maxIncreasingDumbbellsSumUtil(rack, i, totalWeight);
        // Choose element which is smaller than last element.
        if(rack[i - 1] < rack[n - 1] && temp + rack[n - 1] > currWeight)
        {
            currWeight = temp + rack[n - 1];
        }
    }

    // Store the maximum weigth in 'totalWeight'.
    if(currWeight > totalWeight)
    {
        totalWeight = currWeight;
    }

    return currWeight;
}


int maxIncreasingDumbbellsSum(vector<int> &rack, int n)
{
    if(n == 1)
    {
        return rack[n - 1];
    }
    
    int totalWeight = INT_MIN;

    maxIncreasingDumbbellsSumUtil(rack, n, totalWeight);

    return totalWeight;
}
