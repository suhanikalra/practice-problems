class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int t) {
        if( mp.find(key)==mp.end())return "";
        auto &nums= mp[key];string ans="";
        int low= 0;int high=nums.size()-1;
        int mid= ( high-low)/2+low;

        while( low<= high){
             mid= (high-low)/2+low;
            if( nums[mid].first==t){
                return nums[mid].second;
            }
            else if( nums[mid].first>t){
                high= mid-1;
            }
            else{ ans= nums[mid].second; low= mid+1;}
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