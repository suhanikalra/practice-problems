class TextEditor {
public:
    stack<char> left, right;
    TextEditor() {}

    void addText(string text) {
        for (auto c : text) {
            left.push(c);
        }
    }

    int deleteText(int k) {
        int count = 0;
        while (!left.empty() and count < k) {
            left.pop();
            count++;
        }
        return count;
    }
    string getLast10() {
    string ans = "";
    vector<char> buffer;

    int count = 0;
    while (!left.empty() && count < 10) {
        buffer.push_back(left.top());
        left.pop();
        count++;
    }

    // rebuild string in correct order
    for (int i = buffer.size() - 1; i >= 0; i--) {
        ans += buffer[i];
        left.push(buffer[i]);  // restore stack
    }

    return ans;
}

    string cursorLeft(int k) {
        string ans = "";
        int count = 0;
        while (!left.empty() and count < k) {
            right.push(left.top());
            auto a = left.top();
            left.pop();
            count++;
        }
        return getLast10();
    }

    string cursorRight(int k) {
        string ans = "";
        int count = 0;
        while (!right.empty() and count < k) {
            left.push(right.top());
            auto a = right.top();
            right.pop();
            count++;
        }
        return getLast10();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */