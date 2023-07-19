class Solution {
public:
    static bool compare(vector<int>&v1,vector<int>&v2){
        return v1[1]<v2[1];
        
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),compare);
        int n= intervals.size();
        int ans=0;
        int j=0;
        for(int i=1;i<n;i++)
        {
            if(intervals[j][1]>intervals[i][0])
            {
                ans++;
            }
            else
            {
                j=i;
            }
        }
        return ans;
    }
};