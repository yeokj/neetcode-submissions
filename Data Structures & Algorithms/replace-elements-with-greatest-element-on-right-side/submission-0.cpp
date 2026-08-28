class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int val = -1, n = arr.size();

        for (int i = n - 1; i >= 0; --i) {
            int temp = arr[i];
            arr[i] = val;
            val = max(val, temp);
        }
        return arr;
    }
};