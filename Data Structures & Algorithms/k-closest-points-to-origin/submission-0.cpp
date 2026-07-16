class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if (points.size() <= 1 || points.size() == k) return points;
        int pivot = points.size() - 1;
        int start = 0;
        kClosestHelper(points, k, start, pivot);
        return vector<vector<int>>(points.begin(), points.begin()+k);
    }

private:
    void kClosestHelper(vector<vector<int>>& points, int k, int start, int pivot) {
        int j = start;
        float distp = points[pivot][0]*points[pivot][0] + points[pivot][1]*points[pivot][1];
        float disti;
        
        for (int i = start; i < pivot; i++) {
            disti = points[i][0]*points[i][0] + points[i][1]*points[i][1];
            if (disti < distp) {
                swap(points[i], points[j]);
                j++;
            }
        }

        swap(points[j], points[pivot]);
        if (j == k-1) {
            return;
        } else if (j < k-1) {
            kClosestHelper(points, k, j+1, pivot);
        } else {
            kClosestHelper(points, k, start, j-1);
        }
    }
};