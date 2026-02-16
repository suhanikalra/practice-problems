class TimeMap {
public:
unordered_map<string,vector<pair<int,string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
       mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        
        if( mp.find( key)== mp.end())return "";
        auto &nums= mp[key];
        int low= 0;int high= nums.size()-1;
        int mid;int ind=-1;
        while(low<=high){
            mid= (high-low)/2+low;
            if(nums[mid].first==timestamp){return nums[mid].second;}
            else if( nums[mid].first>timestamp){
                high= mid-1;

            }
            else {ind=mid;low= mid+1;}
        }
        if (ind == -1) return "";
        return nums[ind].second;

        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */