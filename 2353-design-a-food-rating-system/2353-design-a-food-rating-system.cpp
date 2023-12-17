class FoodRatings {
public:
   class compare{
       public:
    bool operator() (pair<int,string>const&a,pair<int,string>const&b) {
        
        if(a.first==b.first){
            return a.second>=b.second;
        }
        return a.first<b.first;
    }
       
   };        
   map<string,priority_queue<pair<int,string>,vector<pair<int,string>>,compare>>m; 
   map<string,int>mp;
   map<string,string>v;
    
FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
       for(int i=0;i<foods.size();i++){
           mp[foods[i]]=ratings[i];
            v[foods[i]]=cuisines[i];
       }
       for(int i=0;i<foods.size();i++){
           m[cuisines[i]].push({ratings[i],foods[i]});
       }
    }
    
    
    void changeRating(string food, int newRating) {
        mp[food]=newRating;
        m[v[food]].push({newRating,food});
        
    }
    
    string highestRated(string cuisine) {

        while(true){
            int rating=m[cuisine].top().first;
            string food=m[cuisine].top().second;
            cout<<rating<<" "<<food<<endl;
            if(mp[food]==rating){
                return food;
            }
            m[cuisine].pop();
            if(m[cuisine].empty())
                break;
        }
        return "";
     
    }
};
