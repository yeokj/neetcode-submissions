class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int can = -1;
        int count = 0;

        for (const auto &num : nums) {
            if (count == 0) {
                can = num;
            }
            if (num == can) {
                ++count;
            }
            else {
                --count;
            }
        }
        return can;
    }
};