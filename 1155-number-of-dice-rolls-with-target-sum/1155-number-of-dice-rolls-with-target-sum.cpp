class Solution {
public:
    #define MOD 1000000007
    int numRollsToTarget(int d, int f, int target) {
        vector<vector<int>> dp(d+1, vector<int>(target+1, -1));
        return solve(dp, d, f, target);
    }
    int solve(vector<vector<int>>& dp, int d, int f, int target){
        if(d == 1){
            return target <= f;
        }
        if(dp[d][target] != -1){
            return dp[d][target];
        }
        dp[d][target] = 0;
        for(int i = 1 ; i <= f ; i++){
            if(target - i > 0){
                dp[d][target] = (dp[d][target] + solve(dp, d-1, f, target - i))%MOD;
            }
        }
        return dp[d][target];
    }
};