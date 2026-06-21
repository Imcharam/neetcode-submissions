class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> brackets = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char>open;
        for(char c : s) {
            if (brackets.contains(c)) {
                if (!open.empty() && open.top() == brackets[c]) {
                    open.pop();
                } else {
                    return false;
                }
            } else {
                open.push(c);
            }
        }
        if (open.empty()) {
            return true;
        }
        return false;
    }
};
