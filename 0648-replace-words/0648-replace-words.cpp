class TrieNode{
    public: 
    TrieNode* children[26];
    bool end= false;
    TrieNode(){
    for (int i = 0; i < 26; i++)
        children[i] = nullptr;
}

};
class Solution {
public:
TrieNode* trie;
    Solution() {
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
    string start(string word) {
    TrieNode* node = trie;
    string ans = "";

    for(char w : word){
        if(node->children[w-'a'] == nullptr){
            return word;   
        }

        node = node->children[w-'a'];
        ans += w;

        if(node->end){
            return ans;  
        }
    }

    return word;   
}
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        stringstream ss(sentence);
        string word;string res="";
       
        for( auto a:dictionary){
            insert(a);
        }

         while (ss >> word) {
            
            if(start(word).size()!=word.size())res+= start(word)+" ";
            else res+= word+" ";

        }res.pop_back();
        return res;
    }
};