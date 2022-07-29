/*

    Time Complexity: O(N * (2 ^ (N - 1)))
    Space Complexity: O(N* (2 ^ (N - 1))
    
    Where N is the length of the string S.

*/

#include <unordered_set>
using namespace std;

vector<string> wordBreakHelper(string &s, int idx, unordered_set<string> &dictSet, int size)
{
    // Base Condition
    if (idx == size)
    {
        return {""};
    }

    vector<string> subPart, completePart;
    string word = "";

    /*
        Start exploring the sentence from the index until we wouldn't find 'j' such that substring [index,j] exists in the dictionary as a word.
    */
    for (int j = idx; j < size; j++)
    {

        word.push_back(s[j]);
        if (dictSet.count(word) == 0)
        {
            continue;
        }

        //  Get the answer for rest of sentence from 'j' to s.size().
        subPart = wordBreakHelper(s, j + 1, dictSet, size);

        //  Append "word" with all the answer that we got.
        for (int i = 0; i < subPart.size(); i++)
        {
            if (subPart[i].size() != 0)
            {
                string temp = word;
                temp.append(" ");
                temp.append(subPart[i]);
                subPart[i] = temp;
            }
            else
            {
                subPart[i] = word;
            }
        }

        for (int i = 0; i < subPart.size(); i++)
        {
            completePart.push_back(subPart[i]);
        }
    }
    return completePart;
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    //  Set to check the whether any word exists in the dictionary or not.
    unordered_set<string> dictSet;

    for (int i = 0; i < dictionary.size(); i++)
    {
        dictSet.insert(dictionary[i]);
    }
    return wordBreakHelper(s, 0, dictSet, s.size());
}