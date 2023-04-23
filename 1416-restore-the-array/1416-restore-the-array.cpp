class Solution {
public:
    int mod=1e9+7;
    int fun(int i,int k,string &s,vector<int> &dp){
        if(i==s.size()) return 1;
        if(dp[i]!=-1) return dp[i];
        if(s[i]=='0') return 0;
        long long num=0;
        int ans=0;
        for(int j=i;j<s.size();j++){
            num=num*10+s[j]-'0';
            if(num>k) break;
            ans+=fun(j+1,k,s,dp);
            ans%=mod;
        }
        return dp[i]=ans;
    }
    int numberOfArrays(string s, int k) {
        int n=s.size();
        vector<int> dp(n+1,-1);
        return fun(0,k,s,dp);
    }
};