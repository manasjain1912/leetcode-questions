class Solution {
public:
    int bestClosingTime(string customers) {
        int left=0;
        int right=0;
        left=0;
        for(auto ele:customers){
            if(ele=='Y')
                right++;
        }
        int index=0;
        int penalty=right;
        for(int i=0;i<customers.length();i++)
        {
            if(customers[i]=='N')
            {
                left++;
            }
            else if(customers[i]=='Y')
            {
                right--;
            }
            if(left+right < penalty){
                penalty=left+right;
                index=i+1;
            }
        }
        return index;
    }
};