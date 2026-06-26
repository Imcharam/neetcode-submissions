class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int cycle = 0;
        int student = 0;
        int sandwich = 0;
        while (sandwich < sandwiches.size() && cycle < students.size() - student) {
            if (students[student] == sandwiches[sandwich]) {
                sandwich++;
                student++;
                cycle = 0;
            } else {
                students.push_back(students[student]);
                student++;
                cycle++;
            }
        }
        return students.size() - student;
    }
};