class AllOne {
public:
    unordered_map<string,int> mpp;
    set<pair<int,string>> st;
    AllOne() {
        
    }
    
    void inc(string key) {
        st.erase({mpp[key],key});
        mpp[key]++;
        st.insert({mpp[key],key});
    }
    
    void dec(string key) {
        st.erase({mpp[key],key});
        mpp[key]--;
        if(mpp[key]>0) st.insert({mpp[key],key});
    }
    
    string getMaxKey() {
        if(st.size()==0) return "";
        string ans = st.rbegin()->second;
        return ans;
    }
    
    string getMinKey() {
        if(st.size()==0) return "";
        string ans = st.begin()->second;
        return ans;
    }
};