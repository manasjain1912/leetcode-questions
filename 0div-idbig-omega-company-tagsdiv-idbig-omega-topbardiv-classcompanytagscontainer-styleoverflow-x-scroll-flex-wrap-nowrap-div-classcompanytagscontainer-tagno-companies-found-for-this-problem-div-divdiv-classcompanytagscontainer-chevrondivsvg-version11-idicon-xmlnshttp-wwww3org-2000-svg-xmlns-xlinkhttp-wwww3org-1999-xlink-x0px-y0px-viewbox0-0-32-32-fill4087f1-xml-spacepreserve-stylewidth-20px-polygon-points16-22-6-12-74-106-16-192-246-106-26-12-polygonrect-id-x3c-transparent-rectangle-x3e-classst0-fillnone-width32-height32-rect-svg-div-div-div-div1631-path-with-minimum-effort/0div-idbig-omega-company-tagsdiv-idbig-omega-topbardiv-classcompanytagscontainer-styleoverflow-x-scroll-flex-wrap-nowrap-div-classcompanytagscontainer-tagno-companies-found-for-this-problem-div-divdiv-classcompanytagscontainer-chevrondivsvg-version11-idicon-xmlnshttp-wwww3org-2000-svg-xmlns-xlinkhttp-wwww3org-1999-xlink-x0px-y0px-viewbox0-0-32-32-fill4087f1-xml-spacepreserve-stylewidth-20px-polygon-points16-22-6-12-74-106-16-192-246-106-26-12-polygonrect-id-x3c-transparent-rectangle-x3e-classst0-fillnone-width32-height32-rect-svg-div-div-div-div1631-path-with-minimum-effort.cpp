class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) 
    {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int, int>>>,greater<pair<int, pair<int,int>>>>pq;
        int n=heights.size();
        int m=heights[0].size();
       vector<vector<int>>dist(n,vector<int>(m,1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int rows[]={0,-1,+1,0};
        int cols[]={-1,0,0,+1};
        while(!pq.empty())
        {
            auto it=pq.top();
            pq.pop();
            int dis=it.first;
            int row=it.second.first;
            int col=it.second.second;
            if(row==n-1 && col==m-1)
                return dis;
            for(int i=0;i<4;i++)
            {
                int nrow=rows[i]+row;
                int ncol=cols[i]+col;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
                {
                int newdis=max(abs(heights[nrow][ncol]-heights[row][col]),dis);
                if(newdis<dist[nrow][ncol])
                {
                    dist[nrow][ncol]=newdis;
                    pq.push({newdis,{nrow,ncol}});
                }
                
            }
        }
        }
        return 0;
    }
};
       