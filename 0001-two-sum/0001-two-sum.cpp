class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    int start = 0,i=0;
    vector <pair<int,int>> arr;
    for(auto num: nums){
        arr.push_back({num,i++});
    }
    int end= nums.size()-1;
    sort(arr.begin(),arr.end());
    while(start<=end){
        if(arr[start].first + arr[end].first==target)return {arr[start].second,arr[end].second};
    
    else if(arr[start].first + arr[end].first>target){ end--;}
    else start++;}

     return {};
        
    }
   
};