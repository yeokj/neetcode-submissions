class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return {};
        }
        unordered_map<int, int> numbers;

        for (int i = 0; i < nums.size(); i++) {
            if (numbers.find(target - nums[i]) == numbers.end()) {
                numbers[nums[i]] = i;
            }
            else {
                return vector<int>{numbers[target - nums[i]], i};
            }
        }
        return {};
    }
};
