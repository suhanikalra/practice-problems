class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());

        queue<pair<string,int>> q;
        q.push({ beginWord, 1});
        while( !q.empty()){
            auto ele= q.front();
            q.pop();
            auto word= ele.first;
            auto dist= ele.second;
            if( word==endWord)return dist;
            for( int i=0;i< word.size();i++){
                 for (char ch = 'a'; ch <= 'z'; ch++) {
                    auto temp= word;
                    temp[i]=ch;
                    if(st.find(temp)!= st.end()){
                        q.push({temp,dist+1});
                        st.erase(temp);
                    }
                 }
            }
        }
        return 0;
    }
};