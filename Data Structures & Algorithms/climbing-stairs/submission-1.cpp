class Solution {
public:
    unordered_map<int,int> store;
    int climbStairs(int n) {
        int x = 0;
        if (n == 0) {
            return 1;
        }
        if (store.contains(n)) {
            return store[n];
        }
        if (n >= 2) {
            x += climbStairs(n-2);
        }
        x += climbStairs(n-1);
        store[n] = x;
        return x;
    }
};
