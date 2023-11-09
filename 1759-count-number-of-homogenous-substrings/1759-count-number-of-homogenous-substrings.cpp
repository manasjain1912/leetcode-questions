class Solution {
    unsigned const int mod=1000000007;
public:
    int countHomogenous(string s) {
        int n=s.size();
        
        long long ans=0;
        long long len=1;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                ans = (ans%mod + ((len*(len+1))/2)%mod)%mod;
                len=1;
            }
            else{
                len++;
            }
        }
        ans = (ans%mod + ((len*(len+1))/2)%mod)%mod;
        return ans;
    }
};