class TrieNode{
public:
TrieNode* children[26];
bool stop= false;

TrieNode(){
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;

}
};

class Trie {
public:
TrieNode* root;
    Trie() {
        root= new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node= root;
        for( auto c: word){
        if(node->children[c-'a']==NULL){
            node->children[c-'a']=new TrieNode();
        }
        node= node->children[c-'a'];
        }
        node->stop= true;
    }
    
    bool search(string word) {
        TrieNode* node= root;
        for( auto c: word){
            if(node->children[c-'a']==NULL)return false;
             node= node->children[c-'a'];

        }
        return node->stop;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node= root;
        for( auto c: prefix){
            if(node->children[c-'a']==NULL)return false;
             node= node->children[c-'a'];

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