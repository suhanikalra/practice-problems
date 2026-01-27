class Solution {
public:
    int maxArea(vector<int>& height) {
        int left=0;int right=height.size()-1;int maxarea=0;

        while(left<right){
            int area=(right-left)*min(height[right],height[left]);
            maxarea=max(area,maxarea);
            if(height[right]>height[left])left++;
            else right--;

        }
        return maxarea;
        
    }
};