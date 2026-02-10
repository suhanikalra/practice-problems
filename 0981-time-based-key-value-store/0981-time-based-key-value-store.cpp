class TimeMap {
public:
unordered_map<string,vector<pair<int, string>>>timeMap;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        int start=0;
        int end= timeMap[key].size()-1;
        if( timeMap.find(key)==timeMap.end())return "";
        auto &arr= timeMap[key];
        string ans="";


        while( start<=end){
            int mid= (end-start)/2+start;
            if( arr[mid].first==timestamp ){return arr[mid].second; }
            else if( arr[mid].first<timestamp ){ans=  arr[mid].second;
            start= mid+1;}
            else end= mid-1;
        }
        return ans;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */