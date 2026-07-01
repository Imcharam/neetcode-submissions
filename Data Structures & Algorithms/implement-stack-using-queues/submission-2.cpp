class MyStack {
private:
    struct Node {
        int val;
        unique_ptr<Node> next;
        Node(int val, unique_ptr<Node> next) : val(val), next(std::move(next)) {}
    };
    unique_ptr<Node> q;
public:
    MyStack() : q(nullptr) {}
    
    void push(int x) {
        q = make_unique<Node>(x, std::move(q));
    }
    
    int pop() {
        int top = q->val;
        q = std::move(q->next);
        return top;
    }
    
    int top() {
        return q->val;
    }
    
    bool empty() {
        return q == nullptr;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */