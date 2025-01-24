class Solution {
public:
    int bulbSwitch(int n) {
        // vector<bool>arr(n+1,true);
        // for(int i= 2;i<=n;i++){
        //     int p=1;
        //     while(i*p<=n){
        //         arr[i*p]=!arr[i*p];p++;
        //     }
        // }int count=0;
        // for(auto k:arr){if(k==true)count++;}
        // cout<<count;
        // return count-1;
        return sqrt(n);
        
    }
};