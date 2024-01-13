class Solution {
public:
    int minSteps(string s, string t) {
    int n = s.size();
    int freq[26];
        int count=0;
    memset(freq, 0, sizeof(freq));
    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
    }
    for(int i = 0; i < n; i++)
    {
        freq[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(freq[i]<0)
        {
            count+=freq[i];
        }
    }
    return abs(count);
    }
};
