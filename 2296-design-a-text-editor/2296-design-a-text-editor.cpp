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

    string cursorLeft(int k) {
        string ans = "";
        int count = 0;
        while (!left.empty() and count < k) {
            right.push(left.top());
            auto a = left.top();
            left.pop();
            count++;
        }
        int ten = 10;
        stack<char> temp = left;
        while (!temp.empty() && ten > 0) {
            ans = temp.top() + ans;
            temp.pop();
            ten--;
        }
        return ans;
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
        int ten = 10;
        stack<char> temp = left;
        while (!temp.empty() && ten > 0) {
            ans = temp.top() + ans;
            temp.pop();
            ten--;
        }
        return ans;
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