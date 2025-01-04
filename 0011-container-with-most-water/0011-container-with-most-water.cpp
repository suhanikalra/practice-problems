class Solution {
public:
    int maxArea(vector<int>& height) {
        //https://leetcode.com/problems/count-primes/
       
        int start=0,  end= height.size()-1;
int maxi=0,area=0;
        while(start<=end){
            area= min(height[start],height[end])*(end-start);
            maxi= max(area,maxi);
            if(height[start]<=height[end])start++;
            else end--;
        }
        return maxi;
    }
};