class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, ones = 0;

        for (const int num : nums) {
            if (num == 1) ++ones;
            else {
                result = max(result, ones);
                ones = 0;
            }
        }
        return max(result, ones);
    }
};