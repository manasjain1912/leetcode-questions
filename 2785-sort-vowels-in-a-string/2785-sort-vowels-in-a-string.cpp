class Solution {
public:
    string sortVowels(string s) {
         string ans="", vowel="";
        for(auto x:s){
            if(x=='A'||x=='E'||x=='O'||x=='U'||x=='I'||x=='a'||x=='e'||x=='i'||x=='o'||x=='u'){
                vowel += x;
            }
        }
        sort(vowel.begin(),vowel.end());
        int i=0, n=s.size();
        
        for(int j=0;j<n;j++){
            if(s[j]=='A'||s[j]=='E'||s[j]=='O'||s[j]=='U'||s[j]=='I'||s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'){
                ans.push_back(vowel[i]);
                i++;
            }
            else{
                ans.push_back(s[j]);
            }
        }
        return ans; 
    }
};