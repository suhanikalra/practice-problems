#include <stack>
#include <string>
#include <algorithm>
using namespace std;

class TextEditor {
    stack<char> left;
    stack<char> right;
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        for (auto &c : text) {
            left.push(c);
        }
    }
    
    int deleteText(int k) {
        int cnt = 0;
        while (!left.empty() && k > 0) {
            left.pop();
            cnt++;
            k--;
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        while (!left.empty() && k > 0) {
            char c = left.top();
            left.pop();
            right.push(c);
            k--;
        }
        return cursorShiftString();
    }
    
    string cursorRight(int k) {
        while (!right.empty() && k > 0) {
            char c = right.top();
            right.pop();
            left.push(c);
            k--;
        }
        return cursorShiftString();
    }
    
    string cursorShiftString() {
        string rtn = "";
        int cnt = 10;
        while (!left.empty() && cnt > 0) {
            char c = left.top();
            left.pop();
            rtn += c;
            cnt--;
        }
        reverse(rtn.begin(), rtn.end());
        for (int i = 0; i < rtn.size(); i++) {
            left.push(rtn[i]);
        }
        return rtn;
    }
};
