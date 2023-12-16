class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
        {
            return false;
        }
        unordered_map<char,int>mp;
        for(auto it:s)
        {
            mp[it]++;
        }
         for(auto it:t)
        {
            mp[it]--;
             if(mp[it]<0)
             {
                 return false;
             }
        }
        return true;
    }
};