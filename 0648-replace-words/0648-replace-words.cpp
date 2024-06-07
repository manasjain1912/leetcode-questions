class Solution {
public:
    string replaceWords(vector<string>& d, string s) {
        string ans;
        unordered_map<string, int> m;
        
      
        for (int i = 0; i < d.size(); i++) {
            m[d[i]]++;
        }

        string word = "";
        for (int i = 0; i < s.size(); i++) {
            word.push_back(s[i]);
            
            if (s[i] == ' ') {
                ans += word;
                word = "";
            }

            if (m[word] > 0 ) {
                ans += word;
                while (i + 1 < s.size() && s[i + 1] != ' ') {
                    i++;
                }
                word = "";
            }
        }

        if (!word.empty()) {
            ans += word;
        }

        return ans;
    }
};