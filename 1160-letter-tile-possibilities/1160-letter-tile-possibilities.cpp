

class Solution {
public:
    void backtrack(string& tiles, vector<bool>& used, string res, unordered_set<string>& ans) {
        if (!res.empty()) ans.insert(res); 

        for (int i = 0; i < tiles.size(); i++) {
            if (used[i]) continue;  
            if (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1]) continue; 

            used[i] = true;
            backtrack(tiles, used, res + tiles[i], ans);
            used[i] = false;
        }
    }

    int numTilePossibilities(string tiles) {
        unordered_set<string> ans;
        vector<bool> used(tiles.size(), false);

        sort(tiles.begin(), tiles.end());

       
        backtrack(tiles, used, "", ans);
        
        return ans.size();
    }
};

