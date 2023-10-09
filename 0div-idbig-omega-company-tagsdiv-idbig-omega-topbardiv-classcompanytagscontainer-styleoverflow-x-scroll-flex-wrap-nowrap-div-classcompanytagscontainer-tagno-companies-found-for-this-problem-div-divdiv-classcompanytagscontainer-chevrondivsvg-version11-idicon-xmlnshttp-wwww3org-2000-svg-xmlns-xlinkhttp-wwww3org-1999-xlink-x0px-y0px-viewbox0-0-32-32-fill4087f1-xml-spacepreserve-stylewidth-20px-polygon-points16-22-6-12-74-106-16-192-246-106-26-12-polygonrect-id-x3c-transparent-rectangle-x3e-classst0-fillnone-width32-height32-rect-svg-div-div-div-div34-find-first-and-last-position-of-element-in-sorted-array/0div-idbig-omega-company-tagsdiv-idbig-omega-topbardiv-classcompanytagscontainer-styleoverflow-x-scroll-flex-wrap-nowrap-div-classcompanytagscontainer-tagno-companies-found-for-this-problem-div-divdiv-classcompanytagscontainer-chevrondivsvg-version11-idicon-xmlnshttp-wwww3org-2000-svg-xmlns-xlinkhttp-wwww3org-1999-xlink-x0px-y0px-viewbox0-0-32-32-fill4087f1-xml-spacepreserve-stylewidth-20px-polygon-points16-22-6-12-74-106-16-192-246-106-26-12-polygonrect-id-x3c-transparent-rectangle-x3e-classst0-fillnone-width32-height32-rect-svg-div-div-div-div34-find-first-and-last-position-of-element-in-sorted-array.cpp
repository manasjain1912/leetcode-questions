class Solution {
public:
    int firstOccur(vector<int>nums,int n,int target)
    {
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                high=mid-1;
                continue;
            }
            if(target>nums[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
     int lastOccur(vector<int>nums,int n,int target)
    {
        int low=0,high=n-1;
        int ans=-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid]==target)
            {
                ans=mid;
                low=mid+1;
                continue;
            }
            if(target>nums[mid])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
       int n=nums.size();
        vector<int>ans;
        int first=firstOccur(nums,n,target);
        int last=lastOccur(nums,n,target);
        ans.push_back(first);
        ans.push_back(last);
        return ans;
       
    }
};