class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> remainder;
        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (remainder.contains(rem)) {
                return {remainder[rem], i};
            }
            remainder[nums[i]] = i;
        }
        return {0,0};
    }
};
