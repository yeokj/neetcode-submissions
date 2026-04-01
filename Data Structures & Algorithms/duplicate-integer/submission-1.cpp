class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> duplicates;

        for (int num : nums) {
            if (duplicates.find(num) == duplicates.end()) {
                duplicates.insert(num);
            }
            else {
                return true;
            }
        }
        return false;
    }
};