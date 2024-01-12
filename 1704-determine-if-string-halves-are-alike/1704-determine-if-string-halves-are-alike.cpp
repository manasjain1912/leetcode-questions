class Solution {
public:
    int countVowels(string s)
    {
        int m=s.size();
        int count=0;
        bool ans=false;
        for(int i=0;i<m;i++)
        {
    if(s[i]=='a' || s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' ||s[i]=='U')
            {
                count++;
            }
        }
        return count;
        
    }
    bool halvesAreAlike(string s) {
        string left;
        string right;
        bool ans=false;
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            left+=s[i];
        }
        for(int i=n/2;i<n;i++)
        {
            right+=s[i];
        }
        int temp1=countVowels(left);
        int temp2=countVowels(right);
        if(temp1==temp2)
        {
            ans=true;
        }
        return ans;
    }
};