class AuthenticationManager {
public:
map<string,int>Tokenizer;//token,time
int ttl=0;
    AuthenticationManager(int timeToLive) {
        ttl= timeToLive;
        
        
    }
    
    void generate(string tokenId, int currentTime) {
       Tokenizer[tokenId]=currentTime+ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if( Tokenizer.find(tokenId)!=Tokenizer.end()){
            if( currentTime<Tokenizer[tokenId]){
                Tokenizer[tokenId]=currentTime+ttl;
            }
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count=0;
        for (auto it = Tokenizer.begin(); it != Tokenizer.end(); ) {
            if (it->second <= currentTime) {
                it = Tokenizer.erase(it); 
            } else {
                count++;
                ++it;
            }
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */