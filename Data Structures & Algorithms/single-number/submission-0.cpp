class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int single = 0;

        for (const auto &num : nums) {
            single ^= num;
        }
        return single;
    }
};
