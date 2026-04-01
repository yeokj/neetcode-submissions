class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        mergeSort(nums, left, right);
        
        return nums;
    }
private:
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }

    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> L(nums.begin() + left, nums.begin() + mid + 1);
        vector<int> R(nums.begin() + mid + 1, nums.begin() + right + 1);
        int i = 0;
        int j = 0;
        int k = left;

        while (i < L.size() && j < R.size()) {
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                ++i;
            }
            else {
                nums[k] = R[j];
                ++j;
            }
            ++k;
        }
        while (i < L.size()) {
            nums[k] = L[i];
            ++i;
            ++k;
        }
        while (j < R.size()) {
            nums[k] = R[j];
            ++j;
            ++k;
        }
    }
};