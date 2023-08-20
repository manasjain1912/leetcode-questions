//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:
	  int solve(int prev_index,int index,int nums[],vector<vector<int>>&dp,int n)
    {
        if(index==n) return 0;
        if(dp[index][prev_index+1]!=-1)
        {
            return dp[index][prev_index+1];
        }
       int sum= solve(prev_index,index+1,nums,dp,n);//not pick
        if(prev_index==-1 ||  nums[index]>nums[prev_index])
        {
          sum= max(sum,nums[index]+solve(index,index+1,nums,dp,n));
        }
        return dp[index][prev_index+1]=sum;
    }
	int maxSumIS(int nums[], int n)  
	{  
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(-1,0,nums,dp,n);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends