//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(int index,int sum,int n,vector<int>arr,vector<int>&ans)
    {
        if(index==n)
        {
            ans.push_back(sum);
            return;
        }
        solve(index+1,sum+arr[index],n,arr,ans);//pick
        solve(index+1,sum,n,arr,ans);//not pick
    }
    vector<int> subsetSums(vector<int> arr, int n)
    {
        sort(arr.begin(),arr.end());
        vector<int>ans;
        solve(0,0,n,arr,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends