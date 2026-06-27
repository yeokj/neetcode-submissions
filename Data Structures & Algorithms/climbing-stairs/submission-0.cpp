class Solution {
public:
    vector<int> memo;

    int fib(int n) {
        if (n <= 2) return n;
        if (memo[n] != -1) return memo[n];

        memo[n] = fib(n - 1) + fib(n - 2);
        return memo[n];
    }
    
    int climbStairs(int n) {
        if (n <= 2) return n;

        memo.resize(n + 1, -1);
        return fib(n);
    }
};
