class Solution {
public:
    
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> mp;
        for (int i=0;i<arr.size();i++)
        {
            if (mp.find(arr[i]-difference)!=mp.end()){
                mp[arr[i]]=mp[arr[i]-difference]+1;
            }
            else {
                mp[arr[i]]=1;
            }
        }
        int ans=0;
        for (auto it:mp){
            ans=max(ans,it.second);
        }
        return ans;
    }
};