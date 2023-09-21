//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    vector<int> find(int arr[], int n , int x )
    {
        int minindex=INT_MAX;
        int maxindex=-1;
        for(int i=0;i<n;i++)
        {
            if(arr[i]==x)
            {
                minindex=min(minindex,i);
                maxindex=max(maxindex,i);
            }
        }
        if(minindex==INT_MAX)minindex=-1;
        return {minindex,maxindex};
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        Solution ob;
        ans=ob.find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends