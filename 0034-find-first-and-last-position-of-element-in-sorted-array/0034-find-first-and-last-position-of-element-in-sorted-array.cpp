class Solution {
public:
    int findFirstOccurrence(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;int ans=-1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid]==target){ans= mid;right= mid-1;}
        else if(nums[mid]>target){right=mid-1;}
        else left= mid+1;

    }
    return ans;

}
int findLastOccurrence(const vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;int ans=-1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if(nums[mid]==target){ans= mid;left=mid+1;}
        else if(nums[mid]>target){right=mid-1;}
        else left= mid+1;

    }
    return ans;

}


vector<int> searchRange(vector<int>& nums, int target) {
    int first = findFirstOccurrence(nums, target);
    int last = findLastOccurrence(nums, target);

    return {first, last};
}
};