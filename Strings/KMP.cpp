/*
    Time complexity: O((N - M) * M)
    Space complexity: O(1)

    Where N is the length of string s and M is length of string p.
*/

bool findPattern(string p, string s)
{
    int m = p.size();
    int n = s.size();
  
    for (int i = 0; i <= n - m; i++)
    {
        int j;

        for (j = 0; j < m; j++)
        {
            if (p[j] == s[i + j])
            {
                continue;
            }
            // If there is a mismatch, we do not check furthur.
            else
            {
                break;
            }

        }

        // If j is equal to m then it means p is present in s.
        if (j == m)
        {
            return true;
        }

    }
    
    return false;
}