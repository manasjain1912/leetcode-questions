class Solution {
    public:
vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool>  ans;
        for(int i = 0 ; i < l.size() ; i++)
        {
            vector<int> temp ;
            for(int j = l[i] ; j <= r[i] ; j++)
            {
                temp.push_back(nums[j]);  
            }
            sort(temp.begin() , temp.end()); 
            int f = 0;
            if(temp.size() <= 2){ 
                ans.push_back(true) ;
                f = 1; continue; 
            }
            int d = temp[1]-temp[0];
            for(int pos = 2 ; pos < temp.size() ; pos++ ){
                if(d != temp[pos] - temp[pos-1]){
                    f = 1;
                    ans.push_back(false);
                    break;
                }
            
            }
            if(f==0)
                ans.push_back(true);
        }
        return ans;
    }
};