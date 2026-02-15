class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int>q;vector<int>vis(isConnected.size(),-1);int count=0;
        
        for( int i=0;i<isConnected.size();i++){
            if( vis[i]==1)continue;
            q.push(i);
            vis[i]=1;
            count++;
            while(!q.empty()){
                auto ele= q.front();
                vis[ele]=1;
                q.pop();
                for( int j=0;j<isConnected.size();j++){
                    if( j== ele)continue;
                    if( vis[j]==-1 and isConnected[j][ele]==1){
                        q.push(j);
                    }
                }
            }
        }
        return count;

    }
};