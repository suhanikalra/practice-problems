class TrieNode{
    public: 
    TrieNode* children[26];
    bool end= false;
    TrieNode(){
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;
}

};
    
class Trie {
public:
TrieNode* trie;
    Trie() {
       trie= new TrieNode(); 
    }
    
    void insert(string word) {
        auto node= trie;
        for(auto w: word ){
            if( node->children[w-'a']==NULL){
                node->children[w-'a']=new TrieNode();
            }
            node=  node->children[w-'a'];
            
            
        }
        node->end= true;
        
    }
    
    bool search(string word) {
        auto node= trie;
        for(auto w: word ){
            if( node->children[w-'a']==NULL){
                return false;
            }
            node=  node->children[w-'a'];
        }
        return node->end== true;
        
    }
    
    bool startsWith(string prefix) {
        auto node= trie;
        for(auto w: prefix ){
            if( node->children[w-'a']==NULL){
                return false;
            }
            node=  node->children[w-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */