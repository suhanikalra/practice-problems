
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
         vector<int>ans;
        int count=0;
       map<vector<int>,int>result;
      for(int i=0;i<grid[0].size();i++){
        for(int j=0;j<grid.size();j++){
            ans.push_back(grid[i][j]);//
            
        }
        for(auto k:ans){
        cout<<k;}
       
        result[ans]++;
        ans.clear();
        
       } 
       

       
            for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            ans.push_back(grid[j][i]);
            
            
        }
        for(auto k:ans){
        cout<<k;}
        if(result[ans]){count+=result[ans]; cout<<"true";}
        ans.clear();
       } 
       return count;

    }
};