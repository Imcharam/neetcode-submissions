class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int one = 0;
        int zero = 0;
        for (int student : students) {
            (student == 0) ? zero++ : one++;
        }
        for (int sandwich : sandwiches) {
            if (zero == 0 && sandwich == 0 || one == 0 && sandwich == 1) {
                break;
            }
            (sandwich == 0) ? zero-- : one--;
            
        }

        return zero + one;
    }
};