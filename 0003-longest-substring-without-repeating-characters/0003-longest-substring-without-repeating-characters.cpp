class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int count=0;
        if(n==0)
        {
            return 0;
        }
    int ans=-1;
    int i=0,j=0;
    while(j<n)
    {
        mp[s[j]]++;
        if(j-i+1==mp.size())
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else if(j-i+1>mp.size())
        {
            while(j-i+1>mp.size())
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
    }
};