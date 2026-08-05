class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> colours(3);
        for (int& num : nums) {
            colours[num]++;
        }
        
        int j = 0;
        for (int i = 0; i < 3; i++) {
            while (colours[i]-- > 0) {
                nums[j++] = i;
            }
        }
    }
};