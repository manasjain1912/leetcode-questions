class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int sum=n*(n+1);
        int tempsum=0;
        sum/=2;
        set<int>s;
        int flag=0;
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]==nums[i])
            {
                ans.push_back(nums[i]);
            }
        }
        for(auto it:nums)
        {
            s.insert(it);
        }
        vector<int>temp;
        for(auto it:s)
        {
            temp.push_back(it);
        }
        for(auto it:temp)
        {
            tempsum+=it;
        }
        sum=abs(sum-tempsum);
        ans.push_back(sum);//missing number
        return ans;
    }
};