class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(nums.size() * 2);
        int i = 0;
        int j = 0;

        while (i < result.size()) {
            if (i > nums.size() - 1) {
                result[i] = nums[j] * 1;
                ++j;
            }
            else {
                result[i] = nums[i];
            }
            i++;
        }
        return result;
    }
};