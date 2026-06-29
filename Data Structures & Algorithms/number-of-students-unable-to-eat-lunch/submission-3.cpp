class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        vector<int> counts(2);

        for (int& student : students) counts[student]++;

        for (int& sandwich : sandwiches) {
            if (counts[sandwich] == 0) return counts[0] + counts[1];
            counts[sandwich]--;
        }
        return 0;
    }
};