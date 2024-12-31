class Solution {
public:
   bool wordPattern(string pattern, string s) {
       vector<string>str;
       string word;  
       s=s+" ";
       
       for(auto c: s) {
           if(c != ' ') {
               word += c;
           } else {
               if(!word.empty()) {
                   str.push_back(word);
               }
               word = "";
           }
       }

       if(pattern.size() != str.size()) return false;
       
       unordered_map<char,string> mp;
       unordered_map<string,char> wordToChar;
       
       for(int i=0; i<str.size(); i++) {
           if(mp.find(pattern[i]) == mp.end()) {
               if(wordToChar.count(str[i])) return false;
               mp[pattern[i]] = str[i];
               wordToChar[str[i]] = pattern[i];
           }
           else if(mp[pattern[i]] != str[i]) {
               return false;
           }
       }
       return true;
   }
};