class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int arr[26]={0};
        int s=0;
        for(auto i:chars)
        {
            arr[i-'a']++;
        }
        for(auto i:words)
        {
            int flag=0;
            int temp[26]={0};
            for(auto j:i)
            {
               temp[j-'a']++; 
            }
            for(auto j:i)
            {
                if(temp[j-'a']>arr[j-'a'])
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0){ s=s+i.length();}
            else{flag=0;}
        }
       return s; 
    }
};