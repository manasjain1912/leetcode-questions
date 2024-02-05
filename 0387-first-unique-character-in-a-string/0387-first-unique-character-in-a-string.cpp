class Solution {
public:
    int firstUniqChar(string s)
    {
      int n=s.length();
        map<char,int>mp;
        int ans=-1;
        for(int i=0;i<n;i++)
        {
            mp[s[i]]++;
        }
          for(int i=0;i<n;i++)
        {
            if(mp[s[i]]==1)
            {
                ans=i;
                break;
            }
        }
    return ans;
    }   
};