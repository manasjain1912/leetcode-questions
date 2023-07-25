class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int maxm=0;
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            maxm=max(arr[i],maxm);
            if(arr[i]==maxm)
            {
                ans=i; 
            }
        }
        return ans;
    }
};