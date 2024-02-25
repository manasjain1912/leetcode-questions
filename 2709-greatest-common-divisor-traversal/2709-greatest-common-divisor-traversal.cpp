class Solution {
private:
    vector<int> par,size;
    int find(int v){
        if(v==par[v]) return v;
        return par[v] = find(par[v]);
    }
    void unite(int u,int v){
        u = find(u);
        v = find(v);
        if(u==v) return;
        if(size[u]>size[v]) swap(u,v);
        size[v] += size[u];
        par[u] = v;
    }
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        if(nums.size() == 1) return true;
        unordered_set<int> unique(nums.begin(),nums.end());
        nums.clear();
        if(unique.find(1)!=unique.end()) return false;
        for(auto e:unique) nums.push_back(e);
        if((int)(nums.size())==0) return true;

        vector<int> isPrime(1e5+1,1);
        isPrime[0] = isPrime[1] = 0;
        for(int i=2;i<1e5+1;++i){
            if(isPrime[i]){
                for(int j=2*i;j<1e5+1;j+=i)
                    isPrime[j] = false;
            }
        }

        par = vector<int>(1e5+1,-1);
        size = vector<int>(1e5+1,0);
        for(auto e:nums) par[e] = e, size[e] = 1;
        
        unordered_map<int,vector<int>> adjlist;
        for(auto n:nums){
            for(int i=1;i<=sqrt(n);++i) if(n%i==0) {
                if(isPrime[i]) adjlist[i].push_back(n);
                if(isPrime[n/i]) adjlist[n/i].push_back(n);
            }
        }
    
        for(auto &[p,rev_mapping_dev]:adjlist){
            if((int)(rev_mapping_dev.size())>1){
                for(int i=1;i<(int)(rev_mapping_dev.size());++i){
                    if(find(rev_mapping_dev[i-1])==find(rev_mapping_dev[i])) continue;
                    unite(rev_mapping_dev[i],rev_mapping_dev[i-1]);
                }
            }
        }

        int groups = 0;
        int group_size = 1;
        for(auto e:nums) if(par[e]==e){
            ++groups;
            group_size = max(group_size,size[e]);
        }
        return groups == 1 && group_size == (int)(nums.size());
    }
};
