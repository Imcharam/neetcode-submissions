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
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        if (pairs.size() <= 1) {
            return pairs;
        }

        int split = pairs.size() / 2;
        
        vector<Pair> arr1(pairs.begin(), pairs.begin() + split);
        vector<Pair> arr2(pairs.begin() + split, pairs.end());

        arr1 = mergeSort(arr1);
        arr2 = mergeSort(arr2);

        int i = 0;
        int j = 0;
        int k = 0;
        while (i < pairs.size()) {
            if (k == arr2.size() || j < arr1.size() && arr1[j].key <= arr2[k].key) {
                pairs[i] = arr1[j];
                j++;
            } else {
                pairs[i] = arr2[k];
                k++;
            }
            i++;
        }
        return pairs;
    }
};
