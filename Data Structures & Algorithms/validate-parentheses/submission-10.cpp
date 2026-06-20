class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> parenthesis {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> brackets;
        for (char c : s) {
            if (parenthesis.count(c)) {
                if (!brackets.empty() && brackets.top() == parenthesis[c]) {
                    brackets.pop();
                } else {
                    return false;
                }
            } else {
                brackets.push(c);
            }
        }
        return brackets.empty();
    }
};
