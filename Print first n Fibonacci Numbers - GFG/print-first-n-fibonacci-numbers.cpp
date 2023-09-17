//{ Driver Code Starts
//Initial function template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

//ans[i]=ans[i-1]+ans[i-2]
class Solution
{
    public:
 
    vector<long long> printFibb(int n) 
    {
        if(n==1)return {1};
        if(n==2)return {1,1};
        vector<long long>ans(n,0);
        ans[0]=1;
        ans[1]=1;
        for(int i=2;i<n;i++)
        {
            ans[i]=ans[i-1]+ans[i-2];
        }
        return ans;
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
        //taking number of elements
        int n;
        cin>>n;
        Solution obj;
        //calling function printFibb()
        vector<long long> ans = obj.printFibb(n);
        
        //printing the elements of vector
        for(long long i:ans)cout<<i<<' ';
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends