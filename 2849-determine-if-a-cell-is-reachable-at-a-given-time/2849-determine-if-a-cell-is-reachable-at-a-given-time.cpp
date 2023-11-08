class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy)    return t != 1;
        
        int dis = max(abs(fx - sx), abs(fy - sy));
        
        if(t < dis) return false;
        
        return true;
        
    }
};