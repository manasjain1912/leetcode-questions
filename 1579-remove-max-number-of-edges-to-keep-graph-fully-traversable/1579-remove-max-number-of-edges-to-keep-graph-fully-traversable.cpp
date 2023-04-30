class Solution {
public:
    bool static cmp(vector<int>&a,vector<int>&b){
        return a[0]>b[0]; 
    }
    int find_par(int node,vector<int>&parent){
        if(parent[node] == node)return parent[node];
        return parent[node] = find_par(parent[node],parent);
    }
    bool Union(int a,int b,vector<int>&parent){
        a = find_par(a,parent);
        b = find_par(b,parent);
        if(a!=b){
            parent[b] = a;
            return true;
        }
        return false;
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int>dsu_al(n+1);
        vector<int>dsu_bo(n+1);
        for(int i=0;i<dsu_al.size();i++){
            dsu_al[i] = i;
            dsu_bo[i] = i;
        }
        sort(edges.begin(),edges.end(),cmp);
        int mergeda = 1;
        int mergedb = 1;
        int remove = 0;
        for(auto it : edges){
            if(it[0] == 3){
                bool tmpa = Union(it[1],it[2],dsu_al);
                bool tmpb = Union(it[1],it[2],dsu_bo);
                
                if(tmpa == true)mergeda++;
                if(tmpb == true)mergedb++;
                if(tmpa == false && tmpb == false)remove++;
            }
            else if(it[0] == 1){
                bool tmpa = Union(it[1],it[2],dsu_al);
                if(tmpa == true)mergeda++;
                else
                    remove++;
            }
            else{
                bool tmpb = Union(it[1],it[2],dsu_bo);
                if(tmpb == true)mergedb++;
                else
                    remove++;
            }
        }
        if(mergeda !=n || mergedb !=n)return -1;
        return remove;
    }
};