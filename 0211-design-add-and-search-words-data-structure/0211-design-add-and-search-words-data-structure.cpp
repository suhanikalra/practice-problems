class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd = false;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class WordDictionary {
public:
    TrieNode* root;
    int largest = 0;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* node = root;

        for (auto c : word) {
            if (node->children[c - 'a'] == NULL) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isEnd = true;
        largest = max(largest, (int)word.size());
    }
    bool solve(int i, string word, TrieNode* node) {
        if (!node)
            return false;
        if (i == word.size())
            return node->isEnd;

        char c = word[i];
        if (c == '.') {
            for (int j = 0; j < 26; j++) {
                if (solve(i + 1, word, node->children[j]))
                    return true;
            }
            return false;
        }
    

    else {
        return solve(i + 1, word, node->children[word[i] - 'a']);
    }

}
    
    bool search(string word) {
    if (word.size() > largest)
        return false;
    return solve(0, word, root);
}
}
;

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */