class Solution {
public:
    int minDeletions(string s) {
       vector<int>count(26);
       for(auto i:s)
       {
           count[i-'a']++;
       }
       sort(count.begin(),count.end(),greater<int>());
       int max=count[0]-1;
       int result=0;
       for(int i=1;i<=25;i++)
       {
        if(count[i]!=0)
        {
            if(count[i]>max)
            {
            if(max>0)
            {
                result+=(count[i]-max);
            }
            else{
                result+=count[i];
            }
            }       
            max=min(max-1,count[i]-1);
        }
       }
       return result;
    }
};