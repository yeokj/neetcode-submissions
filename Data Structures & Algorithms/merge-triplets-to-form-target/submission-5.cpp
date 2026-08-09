class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int aI = 0, bI = 0, cI = 0;

        for (const auto &t :triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                aI = max(aI, t[0]);
                bI = max(bI, t[1]);
                cI = max(cI, t[2]);
            }
        }
        return aI == target[0] && bI == target[1] && cI == target[2];
    }
};
