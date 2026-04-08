class Solution {
public:
    vector<vector<int>> result;
    vector<int> v;
    int currSum = 0;

    void backtrack(vector<int> &candidates, int target, int i) {
        if (currSum == target) {
            result.push_back(v);
            return;
        }
        if (currSum > target || i >= candidates.size()) return;

        for (int j = i; j < candidates.size(); ++j) {
            if (j > i && candidates[j] == candidates[j - 1]) 
                continue;
            
            v.push_back(candidates[j]);
            currSum += candidates[j];

            backtrack(candidates, target, j + 1);

            v.pop_back();
            currSum -= candidates[j];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0);

        return result;
    }
};
