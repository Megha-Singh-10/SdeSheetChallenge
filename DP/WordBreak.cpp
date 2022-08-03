/*
    Time Complexity  : O(2 ^ N)
    Space Complexity : O(N)

    Where N is the length of target string.
*/

#include <unordered_set>

// Declare a hash map.
unordered_set < string > hashMap;

bool wordBreakHelper(string s) {

    // Len denotes size of current string.
    int len = s.size();

    // Base case.
    if (len == 0) {
        return true;
    }

    // Run a loop from 1 to length of target string.
    for (int i = 1; i <= len; i++) {
        /*
            If substring from 0 to i exist in hash map
            and remaining string recurs true then return true.
        */
        if (hashMap.find(s.substr(0, i)) != hashMap.end() and wordBreakHelper(s.substr(i, len - i))) {
            return true;
        }
    }

    // If no solution exist then return false.
    return false;
}

bool wordBreak(vector < string > & arr, int n, string & target) {
    // Clear hash map for current test case.
    hashMap.clear();

    // Insert all strings of a into hashmap.
    for (string s: arr) {
        hashMap.insert(s);
    }

    // Call wordBreakHelper to return answer.
    return wordBreakHelper(target);
}