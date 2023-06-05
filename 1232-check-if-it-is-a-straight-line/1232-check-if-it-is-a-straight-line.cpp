class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
          int n=c.size();
        if(n==2)    return true;
        int x=c[1][0]-c[0][0];
        int y=c[1][1]-c[0][1];
        for(int i=2;i<n;i++){
            if(y*(c[i][0]-c[i-1][0])!=x*(c[i][1]-c[i-1][1]))return false;
        }
        return true;
    }
};