class Solution {
public:
    vector<int> majorityElement(vector<int>&arr) {
        vector<int> ans;
        int n = arr.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        for(auto i:mp)
        {
            if(i.second>(n/3))
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};