class Solution {
public:
    void merge(int start, int mid, int end, vector<int>& nums) {
        vector<int> temp;
        int i = start, j = mid + 1;

        while (i <= mid && j <= end) {
            if (nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= end) temp.push_back(nums[j++]);

        for (int k = 0; k < temp.size(); k++)
            nums[start + k] = temp[k];
    }

    void mergesort(int start, int end, vector<int>& nums) {
        if (start >= end) return;

        int mid = start + (end - start) / 2;
        mergesort(start, mid, nums);
        mergesort(mid + 1, end, nums);
        merge(start, mid, end, nums);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(0, nums.size() - 1, nums);
        return nums;
    }
};
