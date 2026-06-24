class BrowserHistory {
    struct ListNode{
        string val;
        ListNode* next;
        ListNode* prev;
        ListNode() : val(""), next(nullptr), prev(nullptr) {}
        ListNode(string val) : val(val), next(nullptr), prev(nullptr) {}
        ListNode(string val, ListNode* next, ListNode* prev) : val(val), next(next), prev(prev) {}
    };

public:
    ListNode* home;
    ListNode* curr;

    BrowserHistory(string homepage) {
        home = new ListNode(homepage);
        curr = home;
    }
    
    void visit(string url) {
        ListNode* newPage = new ListNode(url);
        ListNode* del = curr->next;
        curr->next = newPage;
        newPage->prev = curr;
        curr = curr->next;

        while (del != nullptr) {
            ListNode* nextDel = del->next;
            delete del;
            del = nextDel;
        }
    }
    
    string back(int steps) {
        while (steps != 0 && curr->prev != nullptr) {
            curr = curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while (steps != 0 && curr->next != nullptr) {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */