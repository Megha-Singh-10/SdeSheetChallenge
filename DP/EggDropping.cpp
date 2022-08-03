/*
    Time Complexity: O(K ^ N)
    Space Complexity: O(N + K)

    Where K is the number of axes and N is capacity of log cutting stand.
*/

int cutLogs(int k, int n)
{
    // Check if N or K is less than 1
    if(n <= 1 || k <= 1)
    {
        return n;
    }

    int ans = n;
	
    // Iterate i from 1 to N + 1
    for(int i=1; i <= n; i++)
    {
        int cur = max( cutLogs(k-1, i-1), cutLogs(k, n-i) );
        
        // Update ans with minimum of ans and cur
        ans = min(ans, cur);
    }

    return ans + 1;
}

