class Solution {
public:
    vector<string>ans;
    map<int,string>mp;
    void backtrack(string& dig,int start,string &temp){
        
        if(start==dig.size())ans.push_back(temp);

          for(auto x:mp[dig[start]-'0']){
              temp.push_back(x);
              backtrack(dig,start+1,temp);
              temp.pop_back();
          }
    }
    vector<string> letterCombinations(string dig) {
        if(dig=="") return ans;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";
        string temp;
        backtrack(dig,0,temp);
        return ans;
    }
};