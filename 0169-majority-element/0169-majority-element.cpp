class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
       int count=0;
        int candidates=0;
        for(auto it:nums)
        {
            if(count==0)
            {
                candidates=it;
            }
            if(it==candidates)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return candidates;
    }
};