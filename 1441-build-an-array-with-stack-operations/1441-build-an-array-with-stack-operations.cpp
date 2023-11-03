class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<string> ans;
        int i=0, j=1;
        while(i<target.size())
        {
            if(i==target.size()) break;
            
            if(j==target[i]) 
            {
                ans.push_back("Push");
                j++;
                i++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
                j++;
            } 
        }
        return ans;
        
    }
};