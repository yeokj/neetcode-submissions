class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int stepOne = 1, stepTwo = 2;

        for (int i = 3; i <= n; ++i) {
            int temp = stepOne + stepTwo;
            stepOne = stepTwo;
            stepTwo = temp;
        }
        return stepTwo;
    }
};
