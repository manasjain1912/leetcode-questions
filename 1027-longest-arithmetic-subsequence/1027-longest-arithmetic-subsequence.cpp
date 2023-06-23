class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
       if(nums.size() <=2 ) return nums.size();
        int n = nums.size();
        vector<vector<int>> dp(n+1 , vector<int>(1002 , 1));
        int ans = 1;
        for(int i = 1;i<nums.size();i++)
        {
            for(int j = 0;j<i;j++)
            {
                int diff = nums[i]-nums[j]+500; 
                dp[i][diff] = max(dp[i][diff] , 1+dp[j][diff]);

                
                ans = max(ans , dp[i][diff]);
            }
        }
        return ans;  
    }
};