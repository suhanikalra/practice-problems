class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        vector<int> res;
        queue<int> q;
        q.push(kill);
        unordered_map<int, vector<int>> relation;
        for(int i=0; i<pid.size(); i++)
        {
            relation[ppid[i]].push_back(pid[i]);
        }

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            res.push_back(curr);

            for(int i=0; i<relation[curr].size(); i++)
                q.push(relation[curr][i]);
        }

        return res;
    }
};