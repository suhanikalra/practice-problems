class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int low=0;int ans=-1;
        int high=arr.size()-1;
        while(low<=high){
            int mid=(high-low)/2+low;
            if(arr[mid]==mid){ans= mid;high= mid-1;}
            else if(arr[mid]>mid)high=mid-1;
            else low= mid+1;
        }
        return ans;

    }
};