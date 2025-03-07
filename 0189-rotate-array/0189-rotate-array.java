class Solution {
    public void rotate(int[] nums, int k) {
        
        int n= nums.length;
        k=k%n;
        rev(nums,0,n-k-1);
        rev(nums,n-k,n-1);
        rev(nums,0,n-1);

        
    }
    private void rev(int[] nums, int i, int j){
        while(i<=j){
            int temp= nums[i];
            nums[i]=nums[j];
            nums[j]= temp;
            i++;j--;
        }
    }
}