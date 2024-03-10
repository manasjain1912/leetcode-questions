class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int>s1,s2;
        vector<int>ans;
        for(auto val:nums1)
            s1.insert(val);
        for(auto val:nums2)
            s2.insert(val);
        for(auto val:s1)
        {
           if(s2.find(val)!=s2.end()) 
               ans.push_back(val);
        }
        return ans;
    }
};