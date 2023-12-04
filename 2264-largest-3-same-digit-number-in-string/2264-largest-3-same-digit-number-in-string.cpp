class Solution {
public:
    int count(string s)
    {
        unordered_set<char>st;
        for(auto it:s)
        {
            st.insert(it);
        }
        return st.size();
    }
    string largestGoodInteger(string num) {
        int n=num.size();
        string ans="";
        string temp="";
        for(int i=0;i<n-2;i++)
        {
            for(int j=i;j<i+3;j++)
            {
                temp+=num[j];
            }
            if(count(temp)==1 )
            {
                if(temp[0]>ans[0])
                {
                ans=temp;
                }
            }
            temp="";
        }
        return ans;
    }
};