class Solution {
public:
    void spaceJustify(string &s,int maxWidth,bool lastLine)
    {
        if(s.length()==maxWidth)
            return;
        int ns=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')ns++;
        }
        int spaces_to_be_inserted=maxWidth-s.length();
        if(ns==0 || lastLine)
        {
            s.insert(s.length(),spaces_to_be_inserted,' ');
            return;
        }
        int left_addition=(spaces_to_be_inserted)%(ns);
        int common_addition=(spaces_to_be_inserted)/(ns);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ' &&(left_addition>0 || common_addition))
            {
                int spaces=common_addition;
                if(left_addition)
                {
                    spaces+=1;
                    left_addition--;
                }
                s.insert(i,spaces,' ');
                i+=spaces;
            }
        }
        return ;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
       int n=words.size();
       vector<string>res;
       string line=words[0];
       for(int i=1;i<n;i++)
       {
           if(line.size()+words[i].length()+1<=maxWidth)
           {
               line+=" "+words[i];
           }
           else
           {
               spaceJustify(line,maxWidth,false);
               res.push_back(line);
               line=words[i];
           }
       }
        
       spaceJustify(line,maxWidth,true);
       res.push_back(line); 
       return res;
    }
};