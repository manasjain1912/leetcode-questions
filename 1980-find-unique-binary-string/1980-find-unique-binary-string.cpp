class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int len = nums.size();
        set<string> st(nums.begin(), nums.end());
        for(int i = 0; i < (1 << len); i++)
        {
            string s = "";
            for(int j = 0; j < len; j++)
            {
                if(i & 1 << j)
                    s += '1';
                else
                    s += '0';
            }
            if(!st.count(s))
                return s;
        }
        return "";    
    }
};