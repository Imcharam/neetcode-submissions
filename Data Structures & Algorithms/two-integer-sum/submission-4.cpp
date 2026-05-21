class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // store values
        unordered_map<int,int> remain;
        int leftover;
        // iterate over list
        for(int i = 0; i < nums.size(); i++) {
            leftover = target - nums[i];
            if (remain.contains(leftover)) {
                return {remain[leftover], i};
            } else {
                remain[nums[i]] = i;
            }
        }
        return {0,0};
    }
};
