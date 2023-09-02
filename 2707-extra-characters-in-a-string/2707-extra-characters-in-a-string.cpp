class Solution {
public:
    int rec(int ind,string &s,set<string>&st,vector<int>&dp)
    {
        if (ind==s.size()) return 0;
        if (dp[ind]!=-1) return dp[ind];
        int ans=s.size()-ind;
        for (int i=ind;i<s.size();i++)
        {
           string temp=s.substr(ind,i-ind+1);
           if (st.find(temp)!=st.end())
           {
              ans=min(ans,rec(i+1,s,st,dp));
           }
        }
        ans=min(ans,1+rec(ind+1,s,st,dp));
        return dp[ind]=ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        set<string>st;
        int n=s.size();
        vector<int>dp(n,-1);
        for (auto it:dictionary)
        {
            st.insert(it);
        }
        return rec(0,s,st,dp);
    }
};