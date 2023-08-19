class Solution {
public:
    vector<int> partofmst;
    class disjoint {

        public:

        vector<int> parent;

        disjoint( int size){

            parent.resize(size+1);
            for(int i = 0; i < parent.size() ; i++){

                parent[i] = i;
            }

        }

        int find(int n){

            if (parent[n] == n){

                return n;
            }
            return parent[n] = find(parent[n]);
        }

        void un(int a , int b){

            if (find(a) == find(b)){

                return;
            }

            parent[find(a)] = parent[find(b)];
        }

        
    };

    static bool comp(vector<int> &a , vector<int>&b){

        if(a[2] < b[2]){

            return true;
        }

        return false;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        partofmst.resize(edges.size() , 0);
        for(int i = 0 ; i < edges.size(); i++){

            edges[i].push_back(i);

        }

        sort(edges.begin() , edges.end() , comp);

        int mincost = mst(n , edges , -1 , -1);
        vector<int> pseudo;
        vector<int> critical;
        for(int i = 0 ; i < edges.size() ; i++){

            int index = edges[i][3];
            int exclude_cost = mst(n , edges, i , -1);

            if(exclude_cost > mincost){
                

                critical.push_back(index);
            }
            else if (exclude_cost < mincost){


                critical.push_back(index);

            }
            else {

                int include_cost = mst(n ,edges , -1 , i);
                if (include_cost == mincost){

                    pseudo.push_back(index);
                }
            }
        }

        return {critical , pseudo};

    }



    int mst(int n , vector<vector<int>>& edges , int discard , int include){

        disjoint d(n);
        int ans = 0;
        
        if(include != -1){
            d.un(edges[include][0] , edges[include][1]);
            ans += edges[include][2];
        }

        for(int i = 0 ; i < edges.size() ; i++){

            if(i == discard || i == include){
                continue;
            }

            int a = edges[i][0];
            int b = edges[i][1];
            int cost = edges[i][2];

            if(d.find(a) != d.find(b)){
                
                partofmst[edges[i][3]] = 1;
                ans += cost;
                d.un(a , b);
            }

        }

        return ans;

    }
};