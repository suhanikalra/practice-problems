class Solution {
public:
int solve(int mid,vector<int>& candies, long long p){
    long long count=0;
    for(auto k: candies){
         count += k / mid;}
        
return (count>=p);
    }

    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0;
        for(auto p: candies)sum+=p;
        if (sum < k) return 0;
        int low= 1;
        int high= *max_element(candies.begin(), candies.end()); 
        int ans=candies[0];
        while(low<=high){
            int mid= (high - low)/2+ low;
            if(solve(mid,candies,k)== true){ ans= mid; low=mid+1;}
            else high= mid-1;
        }
        return ans;
    }
};