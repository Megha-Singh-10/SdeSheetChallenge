/*
    Time Complexity: O(N ^ 3)
    Space complexity: O(1)

    Where 'N' is the number elements present in the given array.
 */

vector<int> maxMinWindow(vector<int> arr, int n) 
{
    // Definition: answer[i] will store the maximum of minimum of every window of size 'i'.
    vector<int> answer(n);
    
	for (int i = 0; i < n; ++i) 
	{
        answer[i] = INT_MIN;
    }

    // Sliding on all possible windows
    for (int i = 0; i < n; ++i) 
	{
        for (int j = i; j < n; ++j) 
		{

            // Start is the starting index of current window
            int start = i;

            //  End is the ending index of current window
            int end = j;

            // Temp will store minimum element for the current window
            int temp = INT_MAX;
            for (int k = start; k <= end; ++k) 
			{
                temp = min(temp, arr[k]);
            }
            
			int length = end - start;

            // Update the answer of current window length
            answer[length] = max(answer[length], temp);
        }
    }

    return answer;
}

