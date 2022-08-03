/*
    Time Complexity: O(N ^ 3) 
    Note: It is the upper bound. In real Time Complexity will be much lesser.
    
    Space Complexity: O(N * N)

    Where 'N' is the number of elements in the array.
*/ 

// Take 2D array for memoization
int dp[102][102];


// Utility function to find the minimum cost (scalar multiplication) matrix multiplication
int calculateCost(vector<int> &arr, int i, int j)
{
    // Base case
    if(i >= j)
    {
        return 0;
    }

    /*
        If dp[i][j] is not -1, it means the subproblem has been computed before
        Avoid recomputation of subproblem
    */
    if(dp[i][j] != -1)
    {
        // Return dp[i][j]
        return dp[i][j];
    }

    // Take variable 'ans' to store the answer, initialize it to bigger value 
    int ans = INT_MAX;

    // Run a loop from 'i' to 'j' - 1 and calculate for all possible combination
    for(int k = i; k < j; k++)
    {
        // Store the temporary answer in 'temp'
        int temp = calculateCost(arr, i, k) + calculateCost(arr, k + 1, j) + (arr[k] * arr[i - 1] * arr[j]);
        
        // If temporary answer 'temp' is less than 'ans', update 'ans'
        ans = min(ans, temp);
    }

    // Store the calculated answer 'ans' of this subproblem from [i...j] at dp[i][j] 
    dp[i][j] = ans;

    // Return 'ans'
    return ans;
}

int matrixMultiplication(vector<int> &arr, int N)
{
    
    // Initialize 'dp' with -1   
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            dp[i][j] = -1;
        }
    }

    // Call helper function 'calculateCost' and store the return value in 'ans'
    int ans = calculateCost(arr, 1, N - 1);

    // Return answer 'ans'
    return ans;
}