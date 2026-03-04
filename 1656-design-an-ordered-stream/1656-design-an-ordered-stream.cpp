
class OrderedStream {
public:
    vector<string> arr;
    int ptr;

    OrderedStream(int n) {
        arr.assign(n + 1, "");
        ptr = 1;
    }
    
    vector<string> insert(int idKey, string value) {
        arr[idKey] = value;
        vector<string> chunk;

        while (ptr < (int)arr.size() && arr[ptr] != "") {
            chunk.push_back(arr[ptr]);
            ptr++;
        }
        return chunk;
    }
};