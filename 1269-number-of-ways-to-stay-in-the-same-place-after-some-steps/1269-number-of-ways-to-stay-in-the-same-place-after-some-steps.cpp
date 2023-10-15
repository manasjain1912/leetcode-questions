class Solution {
public:
    #define ll long long
    ll mod = 1000000007;
    ll getways(int steps, int pos, int &arrLen, vector<vector<ll>>& dp){
        if(pos < 0 || pos == arrLen){
            return 0;
        }
        else if(steps == 0){
            return pos == 0;
        }
        else if(dp[steps][pos] != -1){
            return dp[steps][pos];
        }
        else{
            return dp[steps][pos] = (getways(steps-1,pos-1,arrLen,dp) + getways(steps-1,pos+1,arrLen,dp) + getways(steps-1,pos,arrLen,dp)) % mod;
        }
    }
    int numWays(int steps, int arrLen) {
        ios_base::sync_with_stdio(0);
        vector<vector<ll>>dp(steps+1,vector<ll>(steps+1,-1));
        return getways(steps,0,arrLen,dp);
    }
};