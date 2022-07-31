/*
    Time Complexity: O(N*M)
    Space Complexity: O(N)

    Where 'N' is the length of the string 'str' and 'M' is the length of 'pat'
*/

vector<int> stringMatch(string &str, string &pat) 
{

    vector<int> result;

    // Iterate through all possible starting indices
    for (int i = 0; i <= str.length() - pat.length(); i++) 
    {
    
        bool flag = 1;

        for (int j = 0; j < pat.size(); j++) 
        {
            // If a character mismatch occurs
            if (str[i + j] != pat[j]) 
            {
                flag = 0;
            }
        }

        if (flag == 1) 
        {
            result.push_back(i);
        }
    }

    return result;
}