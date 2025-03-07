class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>arr(grid.size()*grid[0].size()+1,0);
        vector<int>ans;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                arr[grid[i][j]]++;
                if(arr[grid[i][j]]==2)ans.push_back(grid[i][j]);
            }
        }
        for(int i=1;i<arr.size();i++){
            if(arr[i]==0)ans.push_back(i);
        }

        return ans;
    }
};