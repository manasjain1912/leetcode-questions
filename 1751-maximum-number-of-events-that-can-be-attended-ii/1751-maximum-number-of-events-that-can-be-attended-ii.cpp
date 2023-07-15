class Solution {
public:
    int findNonOverlappingNextInterval( vector<vector<int>>& jobs, int ind){
        int n = jobs.size() , low = ind+1, high = n-1 , ans = n ;
        while(low <= high ){
            int mid = low + ( high - low )/2 ;
            if(jobs[mid][0] > jobs[ind][1]){
                ans = mid ;
                high = mid-1 ;
            }
            else
                low = mid+1;
        }
        return ans ;
    }
    
    int cal(int ind,int k, vector<vector<int>>& jobs, vector<vector<int>>&dp){
        if(ind == -1 || ind == jobs.size() || k<=0)
            return 0 ;
        if(dp[ind][k] != -1)
            return dp[ind][k] ;
        
        int nextInd = findNonOverlappingNextInterval(jobs, ind);
       
        int inc =  jobs[ind][2] + cal(nextInd,k-1, jobs, dp) ;
       
        int exc = cal(ind+1,k ,jobs, dp) ;
        
        return dp[ind][k] = max(inc, exc) ;
    }
    int maxValue(vector<vector<int>>&jobs, int k) {
        int sz = jobs.size() ;
        sort(jobs.begin(), jobs.end()) ;
        vector<vector<int>>dp(sz+1, vector<int>(k+1, -1)) ;
        return cal(0,k, jobs, dp) ;
    }
};