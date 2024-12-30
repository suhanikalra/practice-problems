class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
         if (matrix.empty() || matrix[0].empty()) return false;
        int top=0;
        int right= matrix[0].size()-1;
        while(top<matrix.size() and right>=0){
            if(matrix[top][right]==target){return true;}
            else if(matrix[top][right]>target){
                right--;
            }
            else top++;
        }
        return false;
    }
};