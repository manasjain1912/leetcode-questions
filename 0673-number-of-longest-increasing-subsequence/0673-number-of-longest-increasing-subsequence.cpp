class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        
        int n = nums.size(), longest = 1, ans = 0;
        vector<int> dp(n, 1), count(n, 1);

        for(int i = n - 1; i >= 0; i--)
        {
            for(int j = i + 1; j < n; j++)
            {
                if(nums[i] < nums[j] && dp[i] <= 1 + dp[j])
                {
                    if(dp[i] < 1 + dp[j])
                        count[i] = 0;
                    count[i] += count[j];
                    dp[i] = 1 + dp[j];
                }
            }
            if(longest <= dp[i])
            {
                if(longest < dp[i])
                    ans = 0;
                longest = dp[i];
                ans += count[i];
            }
            
        }

        return ans;
    }
};