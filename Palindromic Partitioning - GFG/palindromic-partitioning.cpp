//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool isPal(int i,int j,string &s)
    {
        while(i<j)
        {
        if(s[i]!=s[j]) return false;
        i++;
        j--;
        }
        return true;
    }
    int solve(int i,int n,string &str,vector<int>&dp)
    {
        if(i==n)
        return 0;
        if(dp[i]!=-1)
        return dp[i];
        int mn=INT_MAX;
        for(int j=i;j<n;j++)
        {
            if(isPal(i,j,str))
            {
                int temp=1+solve(j+1,n,str,dp);
                mn=min(mn,temp);
            }
        }
        return dp[i]=mn;
    }
    int palindromicPartition(string str)
    {
        int n=str.size();
        vector<int>dp(n,-1);
        return solve(0,n,str,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends