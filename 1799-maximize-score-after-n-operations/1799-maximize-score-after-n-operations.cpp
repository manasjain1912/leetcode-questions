class Solution {
public:
    int dp[8][1<<14];
    int gcd[15][15];
    int fun(vector<int>& nums,int index,int mask){
        if(index-1==nums.size()/2){
            return 0;
        }
        if(dp[index][mask]!=-1)return dp[index][mask];
        int temp=0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int tempmask=(1<<i) +(1<<j);
                if((tempmask&mask)==0){
                    temp=max(temp,index*gcd[i][j]+fun(nums,index+1,mask|tempmask));
                }
            }
        }
        return dp[index][mask]=temp;
    }
    int maxScore(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        memset(gcd,-1,sizeof(gcd));
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                gcd[i][j]=__gcd(nums[i],nums[j]);
            }
        }
        int mask=0;
        return fun(nums,1,mask);
    }
};