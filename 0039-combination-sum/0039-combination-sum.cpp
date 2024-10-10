class Solution {
public:
void solve(vector<int>& cadinates, int target,vector<vector<int>>&ans,int index,vector<int> &temp){
if(target==0) { ans.push_back(temp);}
if(target<0  or index>=cadinates.size()) return;
temp.push_back(cadinates[index]);
solve(cadinates,target-cadinates[index],ans,index,temp);
temp.pop_back();
solve(cadinates,target,ans,index+1,temp);





}


    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> temp;
        solve(candidates,target,ans,0,temp);
      set<vector<int>> st;
        for(auto p : ans){
            st.insert(p);
        }
vector<vector<int>>anss;
        for( auto k: st){
            anss.push_back(k);
        }
        return anss;
    }
};