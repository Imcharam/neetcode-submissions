class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(nums1.begin(), nums1.end()-n);
        int i = 0;
        int j = 0;
        int k = 0;
        while (k < nums1.size()) {
            if (j >= nums2.size() || i < temp.size() && temp[i] <= nums2[j]) {
                nums1[k] = temp[i];
                i++;
            } else {
                nums1[k] = nums2[j];
                j++;
            }
            k++;
        }
    }
};