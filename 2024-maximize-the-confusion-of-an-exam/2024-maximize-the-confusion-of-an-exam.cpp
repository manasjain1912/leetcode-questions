class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.size();
        int i=0,j=0,ans=INT_MIN,count=0;
        //maximum true
        for(j=0;j<n;j++)
        {
            if(answerKey[j]=='F')
            {
                count++;
            }
            while(count>k)
            {
                if(answerKey[i]=='F')
                    count--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        //maximum false
        i=0;
        count=0;
         for(j=0;j<n;j++)
        {
            if(answerKey[j]=='T')
            {
                count++;
            }
            while(count>k)
            {
                if(answerKey[i]=='T')
                    count--;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};