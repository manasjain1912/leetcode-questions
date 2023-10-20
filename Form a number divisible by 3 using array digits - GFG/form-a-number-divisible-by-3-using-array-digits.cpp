//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int digitSum(int num)
  {
      int sum=0;
      while(num>0)
      {
          int temp=num%10;
          sum+=temp;
          num/=10;
      }
      return sum;
  }
  public:
    int isPossible(int N, int arr[]) {
    int sum=0;
    for(int i=0;i<N;i++)
    {
        sum+=digitSum(arr[i]);
    }
    if(sum%3==0) 
    {
         return true;
    }
    return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends