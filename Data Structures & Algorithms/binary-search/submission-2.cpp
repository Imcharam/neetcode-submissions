class Solution {
public:
    int searchHelper(vector<int>& nums, int target, int left, int right) {  
        if (left > right) return -1;
        int half = left + (right - left) / 2;

        if (nums[half] == target) return half;

        return (nums[half] < target) ? 
                searchHelper(nums, target, half + 1, right) :
                searchHelper(nums, target, left, half - 1);
    }

    int search(vector<int>& nums, int target) {
        return searchHelper(nums, target, 0, nums.size()-1);
    }
};
