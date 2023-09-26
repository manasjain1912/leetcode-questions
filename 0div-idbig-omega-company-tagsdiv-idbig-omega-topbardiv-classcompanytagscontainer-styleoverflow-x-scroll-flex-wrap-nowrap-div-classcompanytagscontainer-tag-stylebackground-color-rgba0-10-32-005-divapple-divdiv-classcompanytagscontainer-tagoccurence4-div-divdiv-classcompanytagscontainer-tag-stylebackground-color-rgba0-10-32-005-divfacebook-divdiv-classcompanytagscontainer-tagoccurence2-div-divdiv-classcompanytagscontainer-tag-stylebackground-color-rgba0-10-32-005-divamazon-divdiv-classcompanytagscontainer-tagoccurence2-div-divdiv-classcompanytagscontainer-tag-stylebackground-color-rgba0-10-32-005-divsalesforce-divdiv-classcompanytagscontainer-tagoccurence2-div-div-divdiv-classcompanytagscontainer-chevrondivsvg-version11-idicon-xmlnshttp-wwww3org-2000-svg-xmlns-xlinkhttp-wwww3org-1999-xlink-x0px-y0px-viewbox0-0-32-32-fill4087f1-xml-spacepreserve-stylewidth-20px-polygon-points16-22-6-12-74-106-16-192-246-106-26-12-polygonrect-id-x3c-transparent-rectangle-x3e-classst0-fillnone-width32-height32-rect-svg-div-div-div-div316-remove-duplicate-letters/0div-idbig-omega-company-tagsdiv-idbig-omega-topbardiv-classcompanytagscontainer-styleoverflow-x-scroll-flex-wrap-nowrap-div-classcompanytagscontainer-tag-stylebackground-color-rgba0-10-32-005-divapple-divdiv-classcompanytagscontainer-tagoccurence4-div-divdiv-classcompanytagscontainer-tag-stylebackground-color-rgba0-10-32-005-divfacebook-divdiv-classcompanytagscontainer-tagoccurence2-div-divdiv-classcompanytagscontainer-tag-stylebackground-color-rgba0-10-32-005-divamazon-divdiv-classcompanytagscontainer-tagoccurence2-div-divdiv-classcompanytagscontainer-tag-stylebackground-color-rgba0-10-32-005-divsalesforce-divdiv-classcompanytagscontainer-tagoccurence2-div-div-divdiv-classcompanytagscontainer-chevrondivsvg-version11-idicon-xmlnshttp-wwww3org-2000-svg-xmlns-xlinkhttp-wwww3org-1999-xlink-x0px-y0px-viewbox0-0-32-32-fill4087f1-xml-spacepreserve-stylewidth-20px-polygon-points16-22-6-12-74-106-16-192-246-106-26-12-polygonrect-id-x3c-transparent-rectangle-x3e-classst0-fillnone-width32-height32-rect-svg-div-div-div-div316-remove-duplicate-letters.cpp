class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> freq;
        for(auto it :s){
            freq[it]++;
        }
        
        vector<bool> visited (26,false);
        stack<char> st;
        
        
        for(int i=0;i<s.length();i++){
            freq[s[i]]--;
            
            if(visited[s[i]-'a']){
                continue;
            }
            while(!st.empty()&& s[i]<st.top() && freq[st.top()]>0){
                visited[st.top()-'a']=false;
                st.pop();
            }
            st.push(s[i]);
            visited [s[i]-'a']=true;
        }
        string res ="";
        while(!st.empty()){
            res.push_back(st.top());
            st.pop();
        }
        reverse(res.begin(),res.end());
        return res;
        
    }
};
