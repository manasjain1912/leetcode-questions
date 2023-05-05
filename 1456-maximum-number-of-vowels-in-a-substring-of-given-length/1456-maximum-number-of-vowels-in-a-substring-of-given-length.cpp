class Solution{
public:
    int maxVowels(string s, int k) {
        int count = 0;
        int j = 0;
        int ans = 0, res = 0;
        for(int i=0; i<s.size(); i++){
            count++;                                
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                ans++;
            }
            res = max(res, ans);
			while(count>=k && j<s.size()){
                count--;
                if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                    ans--;                                                                          }
                j++;
            }
        }
        return res;
    }
};