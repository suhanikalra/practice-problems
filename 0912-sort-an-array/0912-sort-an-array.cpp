class Solution {
public:
    vector<int> merge(vector<int>&a, vector<int> &b) {
        vector<int> temp;
       int i = 0, j = 0;
         while (i < a.size() && j < b.size()) {
            if( a[i]>b[j]){
                temp.push_back(b[j++]);
            }
            else{
                temp.push_back(a[i++]);
            }
         }
         while (i < a.size()) temp.push_back(a[i++]);
        while (j < b.size()) temp.push_back(b[j++]);
        return temp;
        
    }
    
    
    vector<int> solve( int low,int high,vector<int>& nums){
        //edge case
        if(low == high)return {nums[low]};
        int mid= (high-low)/2+ low;
        vector<int> a=solve(low,mid,nums); //a is a sorted array
        vector<int> b=solve( mid+1,high,nums);
        return merge( a, b);
        
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int n= nums.size()-1;
       return solve( 0, n,nums);
    }
};