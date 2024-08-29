class DSU{

    public:

    vector<int> par, size;

    DSU(){

        par.resize(20005 , 0);

        size.resize(20005 , 0);

        for(int i=0; i<= 20004; i++) {

            par[i] = i;

        }

    }

    

    

    int find_parent(int u){

        if(par[u] == u) return u;

        return par[u] = find_parent(par[u]);

    }

    

    void connect(int u, int v){

        u = find_parent(u);

        v = find_parent(v);

        

        

        if(u == v) {

            size[u]++;

        }

        else if(size[u] >= size[v]){

            size[u] += size[v] + 1;

            par[v] = u;

        }

        else{

            size[v] += size[u] + 1;

            par[u] = v;

        }

    }

};

class Solution {

public:

    int removeStones(vector<vector<int>>& stones) {

        DSU ds = DSU();

        for(auto p : stones){

            ds.connect(p[0] , p[1] + 10001);

        }

        auto v = ds.par;

        int ans = 0;

        for(int i=0; i < v.size(); i++){

            if(v[i] == i && ds.size[i] > 0 ){

                ans += (ds.size[i] - 1);

            }

        }

        return ans;

    }

};