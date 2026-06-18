class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> scores;
        int sum = 0;
        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] == "+") {
                int num1 = scores.top();
                scores.pop();
                int newTop = (num1 + scores.top());
                sum += newTop;
                scores.push(num1);
                scores.push(newTop);
            } else if (operations[i] == "D") {
                int num = scores.top() * 2;
                sum += num;
                scores.push(num);
            } else if (operations[i] == "C") {
                sum -= scores.top();
                scores.pop();
            } else {
                int num = stoi(operations[i]);
                scores.push(num);
                sum += num;
            }
        }
        return sum;
    }
};