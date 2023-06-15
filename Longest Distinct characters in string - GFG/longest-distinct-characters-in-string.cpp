//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    int n=s.size();
    unordered_map<char,int>mp;
    int ans=-1;
    int i=0,j=0;
    while(j<n)
    {
        mp[s[j]]++;
        if(j-i+1==mp.size())
        {
            ans=max(ans,j-i+1);
            j++;
        }
        else if(j-i+1>mp.size())
        {
            while(j-i+1>mp.size())
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                {
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}

    
            
        
               