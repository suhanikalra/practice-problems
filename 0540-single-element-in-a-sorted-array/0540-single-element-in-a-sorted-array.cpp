class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,h= nums.size()-1;
        int mid= (h-l)/2+l;

//[1,1,2,3,3,4,4,8,8]
// 0 1 2 3 4 5 6 7 8 

        while(l<h){
            mid= (h-l)/2+l;
             if (mid % 2 == 1) mid--; 
            if( mid%2==0 )
            { if( nums[mid]==nums[mid+1]){l= mid+2;}
            else h= mid;}
          
        }
return nums[l];
    }
};