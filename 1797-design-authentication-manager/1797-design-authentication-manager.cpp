class AuthenticationManager {
public:

    unordered_map<string, int>cache;
    queue<pair<int,string>>q;
    int ttl=0;

    AuthenticationManager(int timeToLive) {
        ttl=timeToLive;
    }
    
    void cleanup(int time){
        while(!q.empty() and q.front().first<=time){
            auto ele= q.front();
            q.pop();
            if(cache[ele.second]==ele.first){
                cache.erase(ele.second);
            }
        }
    }

    void generate(string tokenId, int currentTime) {
        cleanup(currentTime);
        cache[tokenId]=currentTime+ttl;
        q.push({cache[tokenId],tokenId});
        
    }
    
    void renew(string tokenId, int currentTime) {
        cleanup(currentTime);
        if(cache.find(tokenId)!= cache.end()){
            if(cache[tokenId]>currentTime){
                cache[tokenId]=currentTime+ttl;
                q.push({cache[tokenId],tokenId});
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        cleanup(currentTime);
        return cache.size();
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */