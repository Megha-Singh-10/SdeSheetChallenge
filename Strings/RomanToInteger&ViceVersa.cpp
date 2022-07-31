/*
    Time Complexity     :   O(N)
    Space Complexity    :   O(N)

    Where 'N' is the length of the string.
*/

#include<unordered_map>

int romanToIntHelper(string s, unordered_map<string, int>& conv) {

    // If single character, return the integer value of that character.
    if (s.size() <= 1) {
        return conv[s];
    }

    // Take first 2 characters.
    string first_two = s.substr(0, 2);

    // If the first 2 characters are in the map, add their value and check rest of the string.
    if (conv.count(first_two)) {
        return conv[first_two] + romanToIntHelper(s.substr(2, s.size() - 2), conv);
    }

    // Otherwise take one charecter and check its value.
    else {
        return conv[s.substr(0, 1)] + romanToIntHelper(s.substr(1, s.size() - 1), conv);
    }
}
int romanToInt(string s) {
    unordered_map<string, int> conv{
        {"M", 1000},
        {"D", 500},
        {"C", 100},
        {"L", 50},
        {"X", 10},
        {"V", 5},
        {"I", 1},
        {"IV", 4},
        {"IX", 9},
        {"XL", 40},
        {"XC", 90},
        {"CD", 400},
        {"CM", 900},
        {"", 0}};
        
    return romanToIntHelper(s, conv);
}