class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList,
                                             vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        int n = firstList.size();
        int m = secondList.size();
        vector<vector<int>> ans;

        while (i < n && j < m) {

            int fs = firstList[i][0];
            int fe = firstList[i][1];

            int ss = secondList[j][0];
            int se = secondList[j][1];

            int commonStart = max(fs, ss);
            int commonEnd = min(fe, se);

            if (commonEnd >= commonStart) {
                ans.push_back({commonStart, commonEnd});
            }
            if (fe > se)
                j++;
            else
                i++;
        }
        return ans;
    }
};