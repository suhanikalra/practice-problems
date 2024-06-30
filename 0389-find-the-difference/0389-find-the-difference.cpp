class Solution {
public:
    char findTheDifference(string s, string t) {
       //approach1
        // unordered_map<char,int>mp;

        // for(char &ch :s){
        //     mp[ch]++;
        // }
        // for(char &ch :t){
        //     mp[ch]--;
        //     if(mp[ch]<0){
        //         return ch;
        //     }
        // }
        
        // return 'd';

    //     //approach 2 sum
    //     int sum_s=0;
    //     int sum_t=0;
    //     for(char &ch : s){
    //         sum_s+=ch;
    //     }
    //     for(char &ch : t){
    //         sum_t+=ch;
    //     }
    //     return sum_t-sum_s;  

    //approach 3 bits
    char ans=0;
    for(char &ch : s){
         ans= ans^ch;
        }
        for(char &ch : t){
           ans= ans^ch;
        }
        return ans;

  }
};