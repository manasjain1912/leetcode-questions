class Solution {
public:
    bool buddyStrings(string s, string g) {
        if(s.size()!=g.size() || (s.size()==1 && g.size()==1 && s==g))
        {
            return false;
        }
        set<char>s1;
        for(auto it:s)
        {
            s1.insert(it);
        }
       if(s==g && s1.size()==1) 
       {
           return true;
       }
        else if(s==g && s1.size()<s.size()) //atleast 1 duplicate
       {
           return true;
       } 
       else if(s==g && s1.size()==s.size()) //all distinct
       {
           return false;
       }
        else
        {
            string temp1="";
            string temp2="";
            int n=s.size();
            int j=0;
            int diff=0;
            for(int i=0;i<n;i++)
            {
                if(s[i]!=g[j])
                {
                    diff++;
                    temp1+=s[i];
                    temp2+=g[j];
                    j++;
                    
                }
                else
                {
                    j++;
                }
            }
            reverse(temp2.begin(),temp2.end());
            if(diff==2 && temp1==temp2)
            return true;
            return false;
        }
    }
};