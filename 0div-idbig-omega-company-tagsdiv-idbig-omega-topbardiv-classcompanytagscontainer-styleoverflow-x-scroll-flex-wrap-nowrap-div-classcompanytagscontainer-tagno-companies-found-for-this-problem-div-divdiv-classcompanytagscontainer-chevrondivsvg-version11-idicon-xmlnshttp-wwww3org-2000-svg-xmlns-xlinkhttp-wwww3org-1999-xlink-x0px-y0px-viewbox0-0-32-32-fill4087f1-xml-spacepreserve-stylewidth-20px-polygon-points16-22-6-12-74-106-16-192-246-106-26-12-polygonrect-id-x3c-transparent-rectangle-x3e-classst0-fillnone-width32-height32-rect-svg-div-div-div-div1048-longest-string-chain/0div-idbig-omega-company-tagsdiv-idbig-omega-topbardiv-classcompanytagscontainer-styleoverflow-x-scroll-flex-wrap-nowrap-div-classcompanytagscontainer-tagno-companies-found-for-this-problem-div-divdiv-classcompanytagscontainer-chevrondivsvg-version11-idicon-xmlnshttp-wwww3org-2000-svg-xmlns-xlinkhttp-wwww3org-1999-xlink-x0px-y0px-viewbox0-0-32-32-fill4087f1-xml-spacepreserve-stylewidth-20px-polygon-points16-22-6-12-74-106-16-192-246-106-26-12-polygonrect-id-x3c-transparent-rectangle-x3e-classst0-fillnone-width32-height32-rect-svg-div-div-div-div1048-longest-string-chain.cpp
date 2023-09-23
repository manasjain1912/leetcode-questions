class Solution {
    bool compare(string &s1, string &s2) {
        
        int i = 0, j = 0;
        int n1 = s1.size(), n2 = s2.size();
        if(n2 - 1 != n1) return false;
        while(j < n2) {
            if(s1[i] == s2[j])
                i++, j++;
            else 
                j++;
        }
        
        if(i == n1 and j == n2)
            return true;
        
        return false;
    }
public:
    static bool comp(string &s1, string &s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
      
        int maxi = 1;
        int n = words.size();
        vector<int> dp(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {

                if(compare(words[j], words[i]) and dp[i] < dp[j] + 1)
                    dp[i] = dp[j] + 1;
            }
            maxi = max(maxi, dp[i]);


        }
        return maxi;
    }
};