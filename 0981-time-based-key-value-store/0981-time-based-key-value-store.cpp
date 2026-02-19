class TimeMap {
public:
unordered_map<string,vector<pair<int, string>>>mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        mp[key].push_back({time,value});
    }
    
    string get(string key, int timestamp) {
        if( mp.find(key)==mp.end())return "";
        auto &nums= mp[key];string ans= "";
        int start= 0;int end= nums.size()-1;
        int mid= (end-start)/2+start;

        while(start<=end){
            mid= (end-start)/2+start;
            if( nums[mid].first==timestamp){ans=nums[mid].second;return ans;}
            else if(nums[mid].first > timestamp ){
                end= mid-1;
            }
            else{ ans= nums[mid].second; start= mid+1;}

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