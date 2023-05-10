//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    int rec(int wt[],int val[],int W,int i,vector<vector<int>>&dp)
    {
        if(i==0)
        {
            if(wt[i]<=W)
            {
                return val[i];
            }
            else
            {
                return 0;
            }
        }
        if(dp[i][W]!=-1)
        return dp[i][W];
        //not pick
        
        int notPick=rec(wt,val,W,i-1,dp);
        int pick=INT_MIN;
        if(wt[i]<=W) //pick
        {
            pick=val[i]+rec(wt,val,W-wt[i],i-1,dp);
        }
        return dp[i][W]= max(pick,notPick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return rec(wt,val,W,n-1,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends