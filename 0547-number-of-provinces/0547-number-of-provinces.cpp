class Solution {
public:
int n=0;
    void dfs( int index,vector<vector<int>>& isConnected,vector<int> &vis ){
        vis[index]=1;
        for( int i= 0;i< n;i++){
             if(vis[i]==-1 and isConnected[i][index]==1 and i!=index){
                    dfs(i,isConnected,vis);
                }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
         n= isConnected.size();int count= 0;

        vector<int> vis( n,-1);

        for( int i =0;i< n;i++){
            for( int j= 0;j<n;j++){
                if(vis[i]==-1 ){
                    dfs(i,isConnected,vis);
                    count++;
                }
            }
        }
        return count;
    }
};