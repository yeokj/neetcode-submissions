class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int i = 0, j = 1, k = 2, n = triplets.size();
        int aI = 0, bI = 0, cI = 0;

        for (const auto &t :triplets) {
            if (t[i] <= target[i] && t[j] <= target[j] && t[k] <= target[k]) {
                aI = max(aI, t[i]);
                bI = max(bI, t[j]);
                cI = max(cI, t[k]);
            }
        }
        return aI == target[i] && bI == target[j] && cI == target[k];
    }
};
