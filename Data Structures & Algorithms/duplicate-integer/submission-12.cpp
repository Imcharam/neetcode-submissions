class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // needs to have a way of storing/memory
        unordered_set<int> memory;
        // needs to iterate
        for(int i = 0; i < nums.size(); i++) {
            int& sub = nums[i];
            if (memory.count(sub) == 0) {
                memory.insert(sub);
            } else {
                return true;
            }
        }
        return false;
    }
};