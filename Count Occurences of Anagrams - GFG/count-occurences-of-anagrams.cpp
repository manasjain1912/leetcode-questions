//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string p, string s) 
	{
	     int k=p.size();
	     int n=s.size();
	     unordered_map<char,int>mp;
	     int i=0,j=0;
	     
	     int ans=0;
	     for(auto it:p)
	     {
	         mp[it]++;
	     }
	     int count=mp.size();
	     while(j<n)
	     {
	         if(mp.find(s[j])!=mp.end())
	         {
	             mp[s[j]]--;
	             if(mp[s[j]]==0)
	             {
	                 count--;
	             }
	         }
	    if(j-i+1<k)
	    {
	        j++;
	    }
	    else if(j-i+1==k)
	    {
	       if(count==0)
	       {
	           ans++;
	       }
	       if(mp.find(s[i])!=mp.end())
	       {
	           mp[s[i]]++;
	           if(mp[s[i]]==1)
	           {
	               count++;
	           }
	       }
	       i++;
	       j++;
	    }
	  }
	  return ans;
	}
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends