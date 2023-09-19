class Solution {
public:
    int findDuplicate(vector<int>& arr) 
    {
        map<int,int>mp;
        int ans;
        for(auto it:arr)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            if(it.second>1)
            {
                ans= it.first;
                break;
            }
        }
        return ans;
    }
};