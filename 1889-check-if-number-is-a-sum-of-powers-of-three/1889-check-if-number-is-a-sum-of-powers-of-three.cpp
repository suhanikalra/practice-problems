class Solution {
public:
void solve(vector<int>&arr,int i,int sum,bool &ans,int n){
    if(sum==n){ans=true;return;}
    if (i >= arr.size() || sum > n) return;
    //include
    solve(arr,i+1,sum+arr[i],ans,n);
    solve(arr,i+1,sum,ans,n);

}

    bool checkPowersOfThree(int n) {
        vector<int> arr;
        int power = 1;
        
        while (power <= n) {
            arr.push_back(power);
            power *= 3;
        }
        int sum = 0;
        bool ans = false;
        solve(arr, 0, sum, ans, n);
        return ans;
    }
};