class Solution {
public:
  bool static cmp(const  pair<pair<int,int>,pair<int,int>> &v1,const  pair<pair<int,int>,pair<int,int>> &v2){
        return v1.first.first<v2.first.first;
    }
     int findpar(int node,vector<int> &par){
    
    if(par[node]==node) return node;
    return par[node]=findpar(par[node],par);
}
 
 
void unionbyrank(int x,int y,vector<int> &par,vector<int> &rank){
    int u=findpar(x,par);
    int v=findpar(y,par);
    
    
    if(rank[u]>rank[v]){
        par[v]=u;
        
     
    }
    else if(rank[v]>rank[u]){
         par[u]=v;
        
      
    }
    else{
        par[v]=u;
       
        rank[u]++;
    }
}
    
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        
        vector<int> par(n);
        vector<int> rank(n);
        
        for(int i=0;i<n;i++){
            par[i]=i;
            rank[i]=0;
        }
       vector<pair<pair<int,int>,pair<int,int>>> v;
        
        for(int i=0;i<queries.size();i++){
            v.push_back({{queries[i][2],i},{queries[i][0],queries[i][1]}});
        }
        
        sort(v.begin(),v.end(),cmp);
        
        vector<pair<int,pair<int,int>>> edges;
        
        for(auto x: edgeList){
            edges.push_back({x[2],{x[0],x[1]}});
        }
        
        sort(edges.begin(),edges.end());
        
        int m = queries.size();
        vector<bool> ans(m);
        int edgeper=0;
        
        for(int i=0;i<m;i++){
           
            while(edgeper<edges.size() and edges[edgeper].first<v[i].first.first){
                unionbyrank(edges[edgeper].second.first,edges[edgeper].second.second,par,rank);
                edgeper+=1;
            }
            
            ans[v[i].first.second]=(findpar(v[i].second.first,par)==findpar(v[i].second.second,par));
        }
        
        return ans;
    }
};