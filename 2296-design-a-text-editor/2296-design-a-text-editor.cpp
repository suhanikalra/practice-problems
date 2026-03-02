#include <iostream>
#include <string>
using namespace std;

class TextEditor {
private:
    string left;   // text to the left of cursor
    string right;  // text to the right of cursor

    string getLast10() {
        int start = max(0, (int)left.size() - 10);
        return left.substr(start);
    }

public:
    TextEditor() {}

    void addText(string text) {
        left += text; 
    }

    int deleteText(int k) {
        int deleted = min(k, (int)left.size());
        left.erase(left.size() - deleted, deleted);
        return deleted;
    }

    string cursorLeft(int k) {
        int move = min(k, (int)left.size());

        right = left.substr(left.size() - move) + right;
        left.erase(left.size() - move, move);

        return getLast10();
    }

    string cursorRight(int k) {
        int move = min(k, (int)right.size());

        left += right.substr(0, move);
        right.erase(0, move);

        return getLast10();
    }
};