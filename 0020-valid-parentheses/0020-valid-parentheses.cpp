class Solution {
public:
    bool isValid(string s) 
    {
       stack<char>st;
       for(int i=0;i<s.size();i++)
       {
           if(s[i]=='(' || s[i]=='{' || s[i]=='[')
           {
               st.push(s[i]);
           }
           else
           {
               if(st.empty())
               {
                   return false;
               }
               char temp=st.top();
               st.pop();
               if((s[i]==')' && temp=='(') || (s[i]=='}' && temp=='{') || (s[i]==']' && temp=='['))
               {
                   continue;
               }
               
               else
               {
                   return false;
               }
           }
       }
        if(!st.empty())
            return false;
        return true;
    }
};