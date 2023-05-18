class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree (n, 0);
        for(int i=0; i<edges.size(); i++)   {
            int v = edges[i][1];
            indegree[v]++;
        }
        vector<int> result;
        vector<bool> vis (n, false);
        for(int i=0; i<n; i++)  {
            if(indegree[i]==0)  {
                result.push_back(i);        
            }
        }
        
        return result;
    }
};