class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
     int oddNum=0;
        for(auto x:arr){
            if(x%2==1) oddNum++;
            else oddNum=0;
            if(oddNum==3) return true;
        }
        
        return false;   
    }
};