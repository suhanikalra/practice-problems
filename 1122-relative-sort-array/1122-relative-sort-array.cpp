class Solution {
public:
    static unordered_map<int, int> mp2;
    static bool comp(int a, int b) {
        bool inA = mp2.count(a);
        bool inB = mp2.count(b);

        if (inA && inB)
            return mp2[a] < mp2[b];

        if (inA)
            return true;

        if (inB)
            return false;

        return a < b;
    }
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        mp2.clear();
        int i = 0;
        for (auto a : arr2) {
            mp2[a] = i++;
        }
        sort(arr1.begin(), arr1.end(), comp);
        return arr1;
    }
};
unordered_map<int, int> Solution::mp2;