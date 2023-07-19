//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
 int solve(int i,int j,string &A, string &B,vector<vector<int>>&dp )
  {
      if(i<0 || j<0)
      {
          return 0;
      }
      if(dp[i][j]!=-1)
      {
          return dp[i][j];
      }
      if(A[i]==B[j])
      {
          return dp[i][j]=1+solve(i-1,j-1,A,B,dp);
      }
      return dp[i][j]=max(solve(i-1,j,A,B,dp),solve(i,j-1,A,B,dp));
  }
    int longestPalinSubseq(string A) {
        int n=A.size();
        string B=A;
        int m=B.size();
       reverse(B.begin(),B.end());
       vector<vector<int>>dp(n,vector<int>(m,-1));
       return solve(n-1,m-1,A,B,dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends