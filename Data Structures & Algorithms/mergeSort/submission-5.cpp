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
        if (pairs.empty()) return pairs;
        vector<Pair> temp(pairs.size(), Pair(0, ""));
        mergeSortHelper(pairs, temp, 0, pairs.size()-1);
        return pairs;
    }
private:
    void mergeSortHelper(vector<Pair>& pairs, vector<Pair>& temp, int left, int right) {
        if (left >= right) return;
        
        int middle = left + (right - left) / 2;

        mergeSortHelper(pairs, temp, left, middle);
        mergeSortHelper(pairs, temp, middle + 1, right);

        int i = left;
        int j = middle + 1;
        int k = left;

        while (k < pairs.size()) {
            if (j > right || (i <= middle && pairs[i].key <= pairs[j].key)) {
                temp[k] = pairs[i];
                i++;
            } else {
                temp[k] = pairs[j];
                j++;
            }
            k++;
        }

        for (int index = left; index <= right; index++) {
            pairs[index] = temp[index];
        }
    }
};
