class Solution {
public:
    string largestOddNumber(string num) {
       int n=num.size();
        int last=-1;
        int llast=-1;
        for(int i=0;i<n;i++)
        {
            if((num[i]-'0')&1)
            {
                last=i;
                llast=max(last,i);
                
            }
        }
        if(last==-1)return "";
        return num.substr(0,llast+1);
    }
};