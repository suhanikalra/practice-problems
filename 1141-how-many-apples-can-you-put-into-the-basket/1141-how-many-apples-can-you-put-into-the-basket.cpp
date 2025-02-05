class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(),weight.end());int i;int sum=0;
        for( i= 0;i<weight.size();i++){
            if(sum+weight[i]<=5000)sum=sum+weight[i];
            else break;
        }
        return i;
    }
};