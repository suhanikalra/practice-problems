class Solution {
public:
bool solve(int mid,vector<int>& position, int m){
    int prev=position[0];
    int i=1;int count=1;
    while(i<position.size()){
       
        if(position[i]-prev>=mid){count++;prev=position[i];}
        i++;
        

    }
    if(count>=m)return true;
    return false;
}
    int maxDistance(vector<int>& position, int m) {
        int start=0;
        int end=*max_element(position.begin(),position.end())-*min_element(position.begin(),position.end());
        sort(position.begin(),position.end());

int ans=0;
        while(start<=end){
            int mid=(end-start)/2+start;
            if(solve(mid,position,m)){ans=mid;start=mid+1;}
            else end=mid-1;
        }
        return ans;

    }
};