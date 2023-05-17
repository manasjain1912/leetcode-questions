//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    int dp[501][501];
    int solve(int i,int j,int arr[])
    {
        if(i>=j)
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        int mn=INT_MAX;
        for(int k=i;k<j;k++)
        {
            int temp=solve(i,k,arr)+solve(k+1,j,arr)+arr[i-1]*arr[j]*arr[k];
            if(temp<mn)
            {
                mn=temp;
            }
        }
        return dp[i][j]=mn;
    }
    int matrixMultiplication(int N, int arr[])
    {
          memset(dp,-1,sizeof(dp));
          return solve(1,N-1,arr);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends