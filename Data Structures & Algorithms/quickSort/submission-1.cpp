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
    vector<Pair> quickSort(vector<Pair>& pairs) {
        if (pairs.empty()) return pairs;
        int start = 0;
        int pivot = pairs.size()-1;
        quickSortHelper(pairs, start, pivot);
        return pairs;
    }
private:
    void quickSortHelper(vector<Pair>& pairs, int start, int pivot) {
        if (start >= pivot) return;
        int j = start;
        for (int i = start; i < pivot; i++) {
            if (pairs[i].key < pairs[pivot].key) {
                swap(pairs[i], pairs[j]);
                j++;
            }
        }
        swap(pairs[j], pairs[pivot]);
        quickSortHelper(pairs, start, j-1);
        quickSortHelper(pairs, j+1, pivot);
    }
};
