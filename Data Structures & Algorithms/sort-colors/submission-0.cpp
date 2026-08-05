class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> colours;
        for (int num : nums) {
            colours[num]++;
        }
        int j = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (colours[j] == 0) {
                j++;
            }
            nums[i] = j;
            colours[j]--;
        }
    }
};