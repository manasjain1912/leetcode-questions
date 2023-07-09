class Solution {
public:
    #define ll long long
    int largestVariance(string s)
    {
        ll n=s.length(),answer=0;
        for(auto i='a';i<='z';i++)
        {
            for(auto j='a';j<='z';j++)
            {
                if(i==j)
                {
                    continue;
                }
                ll count1=0,count2=0,index=0;
                bool condition=false;
                for(ll k=0;k<n;k++)
                {
                    if(s[k]!=i && s[k]!=j)
                    {
                        continue;
                    }
                    else if(s[k]==i)
                    {
                        count1++;
                        if(count2>0)
                        {
                            answer=max(answer,count1-count2);
                        }
                        else if(condition)
                        {
                            answer=max(answer,count1-1);
                        }
                    }
                    else{
                        count2++;
                        condition=true;
                        if(count2>count1)
                        {
                            while(index<n && count2>count1)
                            {
                                if(s[index]==i)
                                {
                                    count1--;
                                }
                                else if(s[index]==j)
                                {
                                    count2--;
                                }
                                index++;
                            }
                        }
                        answer=max(answer,count1-count2);                        
                    }
                }
            }
        }
        return answer;
    }
};