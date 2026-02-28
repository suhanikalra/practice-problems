class TrieNode{
    public: 
    TrieNode* children[26];
    bool end= false;
    TrieNode( ){
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
    
    
};

class MagicDictionary {
public:
TrieNode* trie;
   
    MagicDictionary() {
          trie = new TrieNode(); 
    }
    void insert(string word) {
        auto node = trie;
        for (auto w : word) {
            if (node->children[w - 'a'] == NULL) {
                node->children[w - 'a'] = new TrieNode();
            }
            node = node->children[w - 'a'];
        }
        node->end = true;
    }
    
    void buildDict(vector<string> dictionary) {
        for( auto word: dictionary){
            insert(word);
        }
        
    }
    bool dfs(string &word, int idx, TrieNode* node, bool used) {
    if (!node) return false;

    if (idx == word.size())
        return used && node->end;

    int curr = word[idx] - 'a';

    for (int i = 0; i < 26; i++) {
        if (!node->children[i]) continue;

        if (i == curr) {
            if (dfs(word, idx + 1, node->children[i], used))
                return true;
        } 
        else if (!used) {
            if (dfs(word, idx + 1, node->children[i], true))
                return true;
        }
    }

    return false;
}
    
    bool search(string searchWord) {
         return dfs(searchWord, 0, trie, false);
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */