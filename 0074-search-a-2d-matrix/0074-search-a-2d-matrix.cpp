class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int low=0;
        int n= matrix.size()-1;int m= matrix[0].size()-1;
        int high= m*n-1;
        while(low<=high){
            int mid= (high-low)/2+low;
            if(matrix[mid/m][mid%n]==target)return true;
            else if(matrix[mid/m][mid%n]>target)high=mid-1;
            else low=mid+1;
        }
        return false;
    }
};