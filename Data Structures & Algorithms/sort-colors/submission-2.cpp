class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int,int> colours;
        for (int& num : nums) {
            colours[num]++;
        }
        
        int j = 0;
        for (int i = 0; i <= 3; i++) {
            while (colours[i]-- > 0) {
                nums[j++] = i;
            }
        }
    }
};