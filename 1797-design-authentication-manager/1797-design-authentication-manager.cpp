class AuthenticationManager {
public:
    unordered_map<string,int> mp;
    queue<pair<int,string>> q;   
    int ttl = 0;

    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }

    void cleanup(int currentTime) {
        while (!q.empty() && q.front().first <= currentTime) {
            auto front = q.front();
            int time = front.first;
            string token = front.second;
            q.pop();

            if (mp.find(token) != mp.end() && mp[token] == time) {
                mp.erase(token);
            }
        }
    }

    void generate(string tokenId, int currentTime) {
        cleanup(currentTime);  
        int expiry = currentTime + ttl;
        mp[tokenId] = expiry;
        q.push({expiry, tokenId});
    }

    void renew(string tokenId, int currentTime) {
        cleanup(currentTime);  

        if (mp.find(tokenId) != mp.end() &&
            mp[tokenId] > currentTime) {

            int expiry = currentTime + ttl;
            mp[tokenId] = expiry;
            q.push({expiry, tokenId});
        }
    }

    int countUnexpiredTokens(int currentTime) {
        cleanup(currentTime);   
        return mp.size();
    }
};