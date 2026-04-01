class Solution {
public:
    int maxArea(vector<int>& heights) {
        int areaMax = 0;
        int i = 0;
        int j = heights.size() - 1;

        while (i < j) {
            int width = j - i;
            int height = min(heights[i], heights[j]);

            int areaCurr = width * height;

            if (heights[i] < heights[j]) {
                i++;
            }
            else {
                j--;
            }
            
            areaMax = max(areaCurr, areaMax);
        }
        return areaMax;
    }
};
