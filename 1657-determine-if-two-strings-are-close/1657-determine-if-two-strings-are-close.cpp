class Solution {
public:
    bool closeStrings(string word1, string word2) {
           int freq1[26] = {0};        

        int freq2[26] = {0};

        int n = word1.size();

        int m = word2.size();


        if(n != m) return false;
    

        for(int i = 0; i < n; i++){

            freq1[word1[i] - 'a']++;

        }

        for(int i = 0; i < m; i++){

            if(freq1[word2[i] - 'a'] == 0) return false;

            freq2[word2[i]- 'a']++;

        }

        sort(freq1, freq1 + 26);        

        sort(freq2, freq2 + 26);

        for(int i = 0 ;i < 26; i++){

            if(freq1[i] != freq2[i]) return false;

        }

    return true;

    }
};