class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int s=0,e=arr.size()-1;int mid;
        while(s<e){
             mid= (e-s)/2+s;
            if(arr[mid]>arr[mid+1])e=mid;
            else s= mid+1;
        }
        return s;
        
    }
};