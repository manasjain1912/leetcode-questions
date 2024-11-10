class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if(k==0)return 1;
        int st=0, ans=1e9;
        vector<int>precomp(32, 0);
        for(int i=0; i<nums.size(); i++){
            int val=0;
            for(int j=0; j<32; j++){
                if(nums[i]&(1<<j)){
                    precomp[j]++;
                }
                if(precomp[j]){
                    val|=(1<<j);
                }
            }
            if(val>=k){
                ans=min(ans, i-st+1);
            }
            while(val>=k){
                val=0;
                for(int j=0; j<32; j++){
                    if(nums[st]&(1<<j)){
                        precomp[j]--;
                    }
                    if(precomp[j]){
                        val|=(1<<j);
                    }
                }
                st++;
                if(val>=k){
                    ans=min(ans, i-st+1);
                }
            }
        }
        if(ans==1e9)return -1;
        return ans;
    }
};