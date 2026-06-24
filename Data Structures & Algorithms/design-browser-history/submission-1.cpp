class BrowserHistory {
private:
    vector<string> history;
    int len;
    int cur;

public:
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        cur = 0;
        len = 1;
    }
    
    void visit(string url) {
        if (len < cur + 2) {
            history.push_back(url);
        } else {
            history[cur + 1] = url;
        }
        cur++;
        len = cur + 1;
    }
    
    string back(int steps) {
        cur = (cur - steps > 0) ? cur - steps : 0;
        return history[cur];
    }
    
    string forward(int steps) {
        cur = (cur + steps < len - 1) ? cur + steps : len - 1;
        return history[cur];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */