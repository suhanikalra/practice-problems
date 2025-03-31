class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int ele=-1;
        for(int i=arr.size()-1;i>=0;i--){
           auto k=arr[i];
            arr[i]=ele;
            ele= max(ele,k);
        }
        return arr;
    }
};