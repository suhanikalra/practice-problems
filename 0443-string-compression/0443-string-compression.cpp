class Solution {
public:
    int compress(vector<char>& chars) {
        char prev = chars[0];
        string s = "";
        int count = 1;
        for (int i = 1; i < chars.size(); i++) {
            if (chars[i] == prev)
                count++;
            else {
                if (count == 1)
                    s = s + prev;
                else
                    s = s + prev + to_string(count);
                count = 1;
            }
            prev = chars[i];
        }
        s += prev;
        if (count > 1)
            s += to_string(count);
            int i=0;
            for( auto c: s){
                chars[i++]=c;
            }

        return s.size();
    }
};