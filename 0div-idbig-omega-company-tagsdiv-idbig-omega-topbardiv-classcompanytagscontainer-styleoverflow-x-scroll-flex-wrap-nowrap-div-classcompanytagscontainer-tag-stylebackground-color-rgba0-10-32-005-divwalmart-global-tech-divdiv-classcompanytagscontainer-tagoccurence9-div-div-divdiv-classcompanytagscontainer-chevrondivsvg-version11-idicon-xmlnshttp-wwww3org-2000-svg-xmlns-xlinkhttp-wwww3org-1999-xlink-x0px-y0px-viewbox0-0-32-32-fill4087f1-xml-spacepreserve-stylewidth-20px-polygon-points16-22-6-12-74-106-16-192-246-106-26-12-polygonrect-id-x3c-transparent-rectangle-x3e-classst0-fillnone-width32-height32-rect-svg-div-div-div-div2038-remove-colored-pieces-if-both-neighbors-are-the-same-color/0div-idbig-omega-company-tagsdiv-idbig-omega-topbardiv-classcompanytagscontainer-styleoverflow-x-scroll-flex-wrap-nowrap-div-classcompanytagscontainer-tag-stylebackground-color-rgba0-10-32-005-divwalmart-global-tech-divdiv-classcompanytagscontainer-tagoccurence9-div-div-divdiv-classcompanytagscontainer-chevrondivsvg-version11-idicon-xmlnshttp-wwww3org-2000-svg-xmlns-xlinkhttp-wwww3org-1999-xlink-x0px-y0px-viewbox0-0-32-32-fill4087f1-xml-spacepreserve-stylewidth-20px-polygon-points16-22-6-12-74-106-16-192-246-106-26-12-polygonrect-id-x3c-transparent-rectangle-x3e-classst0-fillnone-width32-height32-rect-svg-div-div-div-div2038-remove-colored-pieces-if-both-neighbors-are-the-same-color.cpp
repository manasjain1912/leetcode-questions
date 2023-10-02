class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        if(n<=2)
        {
            return false;
        }
        int maxa=0;
        int maxb=0;
        int counta=0;
        int countb=0;
        int movesa=0;
        int movesb=0;
        for(int i=0;i<n;i++)
        {
            if(colors[i]=='A')
            {
                counta++;
                if(counta>=3)
                {
                    movesa++;
                }
                maxa=max(maxa,counta);
                
            }
            else
            {
                counta=0;
            }
        }
          for(int i=0;i<n;i++)
        {
            if(colors[i]=='B')
            {
                countb++;
                if(countb>=3)
                {
                    movesb++;
                }
                maxb=max(maxb,countb);
            }
            else
            {
                countb=0;
            }
        }
        if(movesa>movesb)return true;
        return false;
    }
};