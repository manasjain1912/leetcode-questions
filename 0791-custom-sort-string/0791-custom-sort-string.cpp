class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int>mp;
        string ans="";
        for(auto it:s)
        {
            mp[it]++;
        }
        for(auto it:order)
        {
            if(mp.find(it)!=mp.end())
            {
                auto temp=mp.find(it);
                int count=temp->second;
                while(count--)
                {
                    ans+=temp->first;
                }
                mp.erase(it);
            }
        }
        for(auto it:mp)
        {
            int cnt=it.second;
            while(cnt--)
            {
                ans+=it.first;
            }
        }
        return ans;
    }
};