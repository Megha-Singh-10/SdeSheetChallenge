496. Next Greater Element I
/* The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.*/

TC->O(N+MlogN) = O(NlogN)
SC->O(M+N)

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums2.size();
        map<int,int> nge;
        vector<int> ans(nums1.size(),-1);
        stack<int> s;
        for(int i=n-1;i>=0;i--)
        {
            while(!s.empty() && s.top()<=nums2[i])
                s.pop();
            if(!s.empty())
                nge[nums2[i]]=s.top();
            else
                nge[nums2[i]]=-1;
            s.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            ans[i]=nge[nums1[i]]; //sorted map, hence logn time to find
        }
        return ans;
    }
};