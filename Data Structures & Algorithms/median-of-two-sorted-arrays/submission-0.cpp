class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if (m > n) {
            swap(nums1, nums2);
            swap(m, n);
        }
        int l = 0;
        int r = m;

        while (l <= r) {
            int i = l + (r - l) / 2;
            int j = (m + n + 1) / 2 - i;

            int leftA = (i == 0) ? INT_MIN : nums1[i - 1];
            int rightA = (i == m) ? INT_MAX : nums1[i];

            int leftB = (j == 0) ? INT_MIN : nums2[j - 1];
            int rightB = (j == n) ? INT_MAX : nums2[j];

            if (max(leftA, leftB) <= min(rightA, rightB)) {
                if ((m + n) % 2 == 1) {
                    return max(leftA, leftB);
                }
                else {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                }
            }
            else if (leftA > rightB) {
                r = i - 1;
            }
            else {
                l = i + 1;
            }
        }
        return 0.0;
    }
};
