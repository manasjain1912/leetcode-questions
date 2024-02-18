class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        std::sort(meetings.begin(), meetings.end());
        vector<long> meetN(n, 0), roomEnd(n, -1);
        for(auto m : meetings){
            long minEnd = LONG_MAX, minIdx = -1;
            for(int i=0; i<n; i++){
                if(roomEnd[i]<=m[0]){
                    minIdx = i;
                    break;
                }else{
                    if(roomEnd[i]<minEnd){
                        minEnd = roomEnd[i];
                        minIdx = i;
                    }
                }
            }
            meetN[minIdx]++;
            roomEnd[minIdx] = m[1] + max((long)0, roomEnd[minIdx]-m[0]);
        }
        auto maxN = std::max_element(meetN.begin(), meetN.end());
        return std::distance(meetN.begin(), maxN);
    }
    
};