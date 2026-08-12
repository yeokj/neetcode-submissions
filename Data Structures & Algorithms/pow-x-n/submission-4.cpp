class Solution {
private:
    double getSquare(double x, long long n) {
        if (x == 0) return 0;
        if (n == 0) return 1;

        double half = getSquare(x, n / 2);

        if (n % 2 != 0) return x * half * half;
        return half * half;
    }

public:
    double myPow(double x, int n) {
        if (n == 0) return static_cast<double>(1);
        
        long long N = n;
        double result = getSquare(x, N);

        if (n < 0) return 1 / result;
        return result;
    }
};
