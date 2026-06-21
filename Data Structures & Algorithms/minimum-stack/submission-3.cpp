class MinStack {
public:

    stack<int> values;
    stack<int> minValues;

    MinStack() {

    }
    
    void push(int val) {
        values.push(val);
        if (minValues.empty() || minValues.top() > val) {
            minValues.push(val);
        } else {
            minValues.push(minValues.top());
        }
    }
    
    void pop() {
        values.pop();
        minValues.pop();
    }
    
    int top() {
        return values.top();
    }
    
    int getMin() {
        return minValues.top();
    }
};
