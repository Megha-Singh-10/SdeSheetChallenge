(Coding Ninja) Next Greater Element
/* Problem Statement
You are given an array arr of length N. You have to return a list of integers containing the NGE(next greater element) of each element of the given array. The NGE for an element X is the first greater element on the right side of X in the array. Elements for which no greater element exists, consider the NGE as -1. */

TC->O(N)
SC->O(N)

#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> s;
    std::vector<int> ans(n,-1);
    for(int i=n-1;i>=0;i--)
    {
       while(!s.empty() && s.top()<=arr[i])  
          s.pop();
       if(!s.empty())        
          ans[i]=s.top();        
       s.push(arr[i]);
    }
    return ans;
}

//Type-2 Question next greater element if the array is circular

TC->O(2N)
SC->O(N)

#include<stack>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    stack<int> s;
    std::vector<int> ans(n,-1);
    for(int i=2*n-1;i>=0;i--)
    {
       while(!s.empty() && s.top()<=arr[i%n])
          s.pop();
/* Instead of line 43& 44, we can write the following, to avoid writing twice
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