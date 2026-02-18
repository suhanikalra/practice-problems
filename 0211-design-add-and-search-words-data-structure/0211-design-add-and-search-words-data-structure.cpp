class TrieNode {
public:
    bool stop = false;
    TrieNode* children[26];

    TrieNode() {
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class WordDictionary {
public:
    TrieNode* trie;
    int largest = 0;

    WordDictionary() {
        trie = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* node = trie;
        for (char c : word) {
            int idx = c - 'a';
            if (node->children[idx] == nullptr) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->stop = true;
        largest = max(largest, (int)word.size());
    }

    bool h(TrieNode* node, int idx, string& word) {

    if (!node) return false;  

    if (idx == word.size())    
        return node->stop;

    char c = word[idx];

    if (c == '.') {
        for (int j = 0; j < 26; j++) {
            if (node->children[j] != nullptr) {
                if (h(node->children[j], idx + 1, word))
                    return true;
            }
        }
        return false;
    } 
    else {
        return h(node->children[c - 'a'], idx + 1, word);
    }
}


    bool search(string word) {
        if ((int)word.size() > largest) return false; 
        return h(trie, 0, word);
    }
};
