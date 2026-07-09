// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        vector<vector<Pair>> ans(pairs.size());
        if (ans.size() == 0) {
            return ans;
        }
        ans[0] = pairs;
        for (int i = 1; i < pairs.size(); i++) {
            int j = i;
            while (j >= 1 && pairs[j].key < pairs[j-1].key) {
                Pair temp = pairs[j-1];
                pairs[j-1] = pairs[j];
                pairs[j] = temp;
                j--;
            }
            ans[i] = pairs;
        }
        return ans;
    }
};
