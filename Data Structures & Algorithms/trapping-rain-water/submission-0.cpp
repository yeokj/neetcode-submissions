class Solution {
public:
    int trap(vector<int>& height) {
        int maxLeft = 0;
        int maxRight = 0;
        int water = 0;
        int i = 0;
        int j = height.size() - 1;

        while (i < j) {
            if (height[i] < height[j]) {
                if (height[i] < maxLeft) {
                    water += maxLeft - height[i];
                    i++;
                }
                else {
                    maxLeft = height[i];
                    i++;
                }
            }
            else {
                if (height[j] < maxRight) {
                    water += maxRight - height[j];
                    j--;
                }
                else {
                    maxRight = height[j];
                    j--;
                }
            }
        }
        return water;
    }
};
