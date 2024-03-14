class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
         unordered_map<int,int>mp;
        int currsum = 0;
        int count=0;
        nums.insert(nums.begin(),0);
        for(int i=0;i<nums.size();i++)
        {
            currsum = currsum + nums[i];
            
            if(mp.find(currsum - k)!=mp.end())
            {
                count = count + mp[currsum - k];
            }
            mp[currsum]++;
        }
        return count;
    }
};