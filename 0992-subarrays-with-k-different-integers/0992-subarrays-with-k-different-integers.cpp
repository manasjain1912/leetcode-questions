class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return fun(nums,k)-fun(nums,k-1);
    }
    int fun(vector<int>& nums, int k)
    {
        unordered_map<int,int> m;
        int j=0;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            while(m.size()>k)
            {
                m[nums[j]]--;
                if(m[nums[j]]==0)
                    m.erase(nums[j]);
                j++;
            }
            res+=i-j;
        }
        return res;
    }
};
