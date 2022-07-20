(Coding Ninja) Next Smaller Element
/* Problem Statement
You are given an array 'ARR' of integers of length N. Your task is to find the next smaller element for each of the array elements.
Next Smaller Element for an array element is the first element to the right of that element which has a value strictly smaller than that element.
If for any array element the next smaller element does not exist, you should print -1 for that array element. */

TC->O(N)
SC->O(N)

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()>=arr[i])
            s.pop();
        if(!s.empty())
            ans[i]=s.top();
        s.push(arr[i]);
    }
    return ans;
}

//Type-2 Question next smaller element if the array is circular

TC->O(2N)
SC->O(N)

#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> s;
    vector<int> ans(n,-1);
    for(int i=2*n-1;i>=0;i--)
    {
        while(!s.empty() && s.top()>=arr[i%n])
            s.pop();
            /* Instead of line 47& 48, we can write the following, to avoid writing twice
      if (i < n) {
          if (!st.empty()) ans[i] = st.top();
        }
        */
        if(!s.empty())
            ans[i%n]=s.top();
        s.push(arr[i%n]);
    }
    return ans;
}