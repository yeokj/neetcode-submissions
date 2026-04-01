class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(nums.size() * 2);
        int i = 0;
        int n = nums.size();

        while (i < n) {
            result[i] = nums[i];
            result[i + n] = nums[i];
            ++i;
        }
        return result;
    }
};