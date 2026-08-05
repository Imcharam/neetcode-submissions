class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left;
        int right;
        int half = nums.size()/2;
        if (nums[half] < target) {
            left = half + 1;
            right = nums.size() - 1;
        } else if (nums[half] == target) {
            return half;
        } else {
            left = 0;
            right = half - 1;
        }
        return searchHelper(nums, target, left, right);
    }

    int searchHelper(vector<int>& nums, int target, int left, int right) {
        if (left > right) {
            return -1;
        }

        int half = left + (right - left) / 2;

        if (nums[half] < target) {
            left = half + 1;
            right = right;
        } else if (nums[half] == target) {
            return half;
        } else {
            left = 0;
            right = half - 1;
        }
        return searchHelper(nums, target, left, right);
    }
};
