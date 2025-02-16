class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
     int low=0;
        int n= matrix[0].size();int m= matrix.size();
        int high= m*n-1;
        while(low<=high){
            int mid= (high-low)/2+low;
            int row= mid/n;
            int col= mid%n;
            if(matrix[row][col]==target)return true;
            else if(matrix[row][col]>target)high= mid-1;
            else low= mid+1; 
        }
        return false;
    }
};