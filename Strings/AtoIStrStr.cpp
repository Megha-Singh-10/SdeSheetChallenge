/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where 'N' is the length of the string.
*/

int atoiRecursive(string str, int n, int curIdx, int & ans) {

    // Base case (Only one digit).
    if (curIdx == n) {
        return ans;
    }

    // Recur for (n-1), multiply result with 10 and add last digit.
    if (str[curIdx] >= '0'
        and str[curIdx] <= '9') {
        ans = ans * 10 + str[curIdx] - '0';
        return atoiRecursive(str, n, curIdx + 1, ans);
    } 
    else {
        return atoiRecursive(str, n, curIdx + 1, ans);
    }
}

int atoi(string s) {
    bool isNegative = 0;
    int n = s.size();
    if (s[0] == '-') {
        isNegative = 1;
    }

    // Store ans here.
    int ans1 = 0;

    int ans = atoiRecursive(s, n, 0, ans1);

    // If negative, make the number negative.
    if (isNegative) {
        return -1 * ans;
    } 
    else {
        return ans;
    }
}