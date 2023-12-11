class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int>mp;
        for(auto it:arr)
        {
            mp[it]++;
        }
        int temp1=INT_MIN;
        int temp2;
        for(auto it:mp)
        {
            temp1=max(it.second,temp1);            
        }
        for(auto it:mp)
        {
            if(it.second==temp1)
            {
                temp2=it.first;
                break;
            }
        }
        return temp2;
    }
};