class NestedIterator {
private: 
    int i = 0;
    vector<int> flat;
	
    void makeFlat(NestedInteger x) {
        if (x.isInteger()) flat.push_back(x.getInteger());
        else for (auto y: x.getList()) makeFlat(y);
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto x: nestedList) makeFlat(x);
    }
    
    int next() {
        return flat[i++];
    }
    
    bool hasNext() {
        return i < flat.size();
    }
};