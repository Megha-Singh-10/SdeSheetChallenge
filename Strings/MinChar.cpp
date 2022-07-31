/*
    Time complexity: O(N ^ 2)
    Space complexity: O(1)
    
    Where N is length of the string.    
*/

// Function for checking a string is palindrome or not
bool isPalindrome(string str)
{
    int l = str.length();
    int i = 0;
    int j = l - 1;

    while (i < j)
    {
        if (str[i] != str[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minCharsforPalindrome(string str)
{
    int count = 0;

    while (str.length() > 0)
    {
        // If current string is palindrome break the loop
        if (isPalindrome(str))
        {
            break;
        }
        // Otherwise remove the last char and go to next iteration
        else
        {
            count++;
            str.erase(str.begin() + str.length() - 1);
        }
    }
    return count;
}