class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        vector<int>v;
        if(arr.size()==1)
        {
            return true;
        }
        bool ans=true;
        for(auto it:arr)
        {
            mp[it]++;
        }
        for(auto it:mp)
        {
            v.push_back(it.second);
        }
        sort(v.begin(),v.end());
        for(int i=1;i<v.size();i++)
        {
            if(v[i-1]==v[i])
            {
                ans=false;
            }
        }
        return ans;
    }
};