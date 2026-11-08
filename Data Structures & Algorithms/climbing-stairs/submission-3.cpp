class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int stepOne = 1, stepTwo = 2;
        for (int i = 2; i < n; ++i) {
            int nextStep = stepOne + stepTwo;
            stepOne = stepTwo;
            stepTwo = nextStep;
        }
        return stepTwo;
    }
};
