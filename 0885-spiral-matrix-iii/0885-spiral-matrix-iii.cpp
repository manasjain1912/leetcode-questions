class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
       int result=rows*cols;
        int limit=1;
        int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
        int d=0;
        vector<vector<int>>ans={{rStart,cStart}};
        int no=1;
        while(ans.size()!=result)
        {
            for(int i=0;i<limit;i++)
            {
                rStart+=dir[d][0];
                cStart+=dir[d][1];
                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                {
                    ans.push_back({rStart,cStart});
                }
            }
            d=(d+1)%4;
            if(no==2)
            {
                limit++;no=1;
            }
            else no++;      
        }
        return ans;  
    }
};