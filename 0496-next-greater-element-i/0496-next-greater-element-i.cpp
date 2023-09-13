class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n=nums2.size();
        stack<int>st;
        vector<int>nge;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]>=st.top())
            {
                st.pop();
            }
            if(st.empty())
            {
                mp[nums2[i]]=-1;
            }
            else
            {
               mp[nums2[i]]=st.top(); 
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++)
        {
            nge.push_back(mp[nums1[i]]);
        }
        return nge;
    }
};