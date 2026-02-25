class Solution {
public:
static bool comp(int a, int b){
    int x=a,y=b;
    auto counta=0;auto countb=0;
    while( a or b){
        
        if( a%2==1)counta++;a/=2;
        
        if( b%2==1)countb++;b/=2;

    }
    if(counta!=countb)return counta<countb;
    return x<y;
}
    vector<int> sortByBits(vector<int>& arr) {
        sort( arr.begin(),arr.end(),comp);
        return arr;
    }
};