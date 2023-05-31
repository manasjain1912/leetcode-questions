class UndergroundSystem {
public:
   	unordered_map<int, pair<string, int>> mp;
    map<pair<string, string>, vector<int>> mpp;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        if(mp.find(id)!=mp.end())
        {
            mpp[{mp[id].first, stationName}].push_back(t-mp[id].second);
        }
    }
    
    double getAverageTime(string startStation, string endStation) {
        double sum = 0, count = 0;
        if(mpp.find({startStation, endStation})!=mpp.end())
        {
            for(int x : mpp[{startStation, endStation}])
            {
                sum += x;
                count++;
            }
        }
        
        return sum/count;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */