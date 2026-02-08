class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>() );
        int low= 0;int high= citations.size()-1;int ans=0;
        int mid= (high-low)/2+ low;

        while( low<=high){
            mid= (high-low)/2+ low;
            if(citations[mid]>=mid+1 ){ans=mid+1;low=mid+1;}
            else{
                high= mid-1;
            }
        }
        return ans;

    }
};

//[3,0,6,1,5]