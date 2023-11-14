class Solution {
public:
    int countPalindromicSubsequence(string s) {
          vector<int> left(26);
        vector<int> right(26);
        unordered_set<string> h;

        for(int i=0; i<s.size(); i++){
            right[s[i]-'a']++;
        }

        for(int i=0; i<s.size(); i++){
            right[s[i]-'a']--;
            for(int j = 0; j<26; j++){
                if(left[j]>0 && right[j]>0){
                    char x = 'a' + j;
                    string palindrome = "";
                    palindrome+=x;
                    palindrome+=s[i];
                    palindrome+=x;

                    if(h.count(palindrome)==true) continue;
                    h.insert(palindrome);
                }
            }
            left[s[i]-'a']++;
        }
        return h.size();
    }
};