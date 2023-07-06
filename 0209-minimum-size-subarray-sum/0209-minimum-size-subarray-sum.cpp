class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
       int n=arr.size();
        int sum=0,ans=INT_MAX,i=0,j=0;
        for(int j=0;j<n;j++)
        {
            sum+=arr[j];
            while(sum>=target)
            {
                ans=min(ans,j-i+1);
                sum-=arr[i];
                i++;
            }
            
        }
        if(ans==INT_MAX)
        return 0;
        return ans;
    }
};