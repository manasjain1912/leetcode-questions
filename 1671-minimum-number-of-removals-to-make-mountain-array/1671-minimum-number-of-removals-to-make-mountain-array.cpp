class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp1(n,1);  

        int maxi = 1;

        for(int i=1; i<=n-1; i++){

            for(int prev_index = 0; prev_index <= i-1; prev_index ++){

                if( nums[i]>nums[prev_index] && 1 + dp1[prev_index] > dp1[i]){
                    dp1[i] = 1 + dp1[prev_index]; 
                }
            }
        }
        
        vector<int> dp2(n,1);   
        for(int i=n-2; i>=0; i--){

            for(int prev_index = n-1; prev_index >i; prev_index --){

                if( nums[i]>nums[prev_index] && 1 + dp2[prev_index] > dp2[i]){ 
                    dp2[i] = 1 + dp2[prev_index]; 
                }
            }
        }
       
        for(int i=1;i<n-1;i++){
            if(dp1[i]>1&&dp2[i]>1)   
                maxi=max(maxi,dp1[i]+dp2[i]-1);   
        }
      
        return n-maxi;   
    }
};