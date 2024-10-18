class Solution {
public:
   int countMaxOrSubsets(vector<int>& nums) {
        unordered_map<int,int> bORfreq;
        int maxOR = INT_MIN;
        for (int i = 0; i < (int) pow(2, nums.size()); i++) {
            int tempOR = 0;
            for (int j = 0; j < nums.size(); j++)
                if ((i & (1 << j)) != 0)
                    tempOR |= nums[j];
            bORfreq[tempOR]++;
            if(tempOR != 0)
                maxOR = max(maxOR,tempOR);
        }    
        return bORfreq[maxOR];
    }
    
};