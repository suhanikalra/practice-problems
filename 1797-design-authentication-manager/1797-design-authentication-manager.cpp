

class AuthenticationManager {
public:
unordered_map<string,int>mp;
priority_queue<pair<int, string>, vector<pair<int, string>>,greater<pair<int, string>>> pq;
int ttl=0;
    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
       
            mp[tokenId]=currentTime+ttl;
            pq.push({mp[tokenId], tokenId});
    
    }
    
    void renew(string tokenId, int currentTime) {
        if(mp.find(tokenId)==mp.end()){
        }
        else if( mp[tokenId]>currentTime){
            mp[tokenId]=currentTime+ttl;
            pq.push({mp[tokenId], tokenId});
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        while(!pq.empty() and pq.top().first<=currentTime ){
            auto front= pq.top();
            auto time= front.first;
            auto val= front.second;
            pq.pop();
            if( mp.find(val)!=mp.end()){
                if(mp[val]==time){
                    mp.erase(val);
                }
            }
            
        }
        return mp.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */