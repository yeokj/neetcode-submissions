class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prodVec(nums.size(), 1);
        int product = 1;
        int i = 0;

        while (i < nums.size()) {
            prodVec[i] = product;
            product *= nums[i];
            i++;
        }

        i = nums.size() - 1;
        product = 1;

        while (i >= 0) {
            prodVec[i] *= product;
            product *= nums[i];
            i--;
        }
        return prodVec;
    }
};
