class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int i = 0, j = 1, k = 2, n = triplets.size();
        int aI = 0, bI = 0, cI = 0;

        for (int x = 0; x < n; ++x) {
            if (triplets[x][i] > target[i] ||triplets[x][j] > target[j] || triplets[x][k] > target[k]) continue;
            if (triplets[x][i] <= target[i] && triplets[x][j] <= target[j] && triplets[x][k] <= target[k]) {
                aI = max(aI, triplets[x][i]);
                bI = max(bI, triplets[x][j]);
                cI = max(cI, triplets[x][k]);
            }
        }
        return aI == target[i] && bI == target[j] && cI == target[k];
    }
};
