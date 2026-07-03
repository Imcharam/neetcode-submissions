class Solution {
public:
    unordered_map<int,int> store;
    int climbStairs(int n) {
        int one = 1;
        int two = 1;
        int temp;

        while (n > 1) {
            temp = one;
            one = one + two;
            two = temp;
            n--;
        }
        return one;
    }
};
