class Solution {
public:
bool solve(int mid,vector<int>& candies, long long k){
    long long count=0;
    for(auto i: candies){
        count+=i/mid;
        
    }
    return count>=k;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int start=1;int ans=0;
        long long sum=0;
        for(auto k: candies)sum+=k;
        int end= *max_element(candies.begin(),candies.end());
        while(start<=end){
            int mid= (end-start)/2+ start;
            if(solve(mid,candies,k)==true){ans=mid;start=mid+1;}
            else if(solve(mid,candies,k)==false){end=mid-1;}
        }
        return ans;

    }
};