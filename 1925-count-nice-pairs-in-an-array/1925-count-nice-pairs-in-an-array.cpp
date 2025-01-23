class Solution {
public:

int rev(int i){
    int num=0;
    while(i>0){
        int digit= i%10;
        i=i/10;
        num=num*10+digit;

    }
    
    return num;
}
    int countNicePairs(vector<int>& nums) {
        int mod = 1e9 + 7;
        unordered_map<int,int>mp;
        int count=0;
        cout<<rev(49);
        for(int i=0;i<nums.size();i++){
           
               auto diff= nums[i]- rev(nums[i]);
                count = (count + mp[diff]) % mod; 
            mp[diff]++;
            }
        
        // for(auto k: mp){
        //     if(k.second>1)count+=((k.second*(k.second-1)/2)%mod);
        // }
        return count%mod;
        
       
    }
};