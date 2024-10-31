class Solution {
public:
    int maxArea(vector<int>& height) {
        int n= height.size();
        int i=0, j= n-1;
        int water=0; int maxi= 0;

        while(i<j){
            water= min(height[i], height[j])* (j-i);
             maxi= max(water, maxi);

            if (height[i]< height[j]){
                i++;
            }
            else j--;
        }

        return maxi;
        
    }
};