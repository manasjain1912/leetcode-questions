class Solution {
public:
    bool solve(vector<int>&nums, int p1,int p2,bool turn,int i,int j){
        if(i>j) return p1>=p2;
        if(turn){
            bool spick=solve(nums,p1+nums[i],p2,0,i+1,j);
            bool epick=solve(nums,p1+nums[j],p2,0,i,j-1);
            return spick || epick;
        }
        else{
            bool spick=solve(nums,p1,p2+nums[i],1,i+1,j);
            bool epick=solve(nums,p1,p2+nums[j],1,i,j-1);
        return spick && epick;

        }

    }
    bool PredictTheWinner(vector<int>& nums) {
        int p1=0,p2=0;
        return solve(nums,p1,p2,1,0,nums.size()-1);
    }
};