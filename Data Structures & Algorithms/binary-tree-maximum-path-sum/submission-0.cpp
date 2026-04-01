/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxSum = INT_MIN;
    int dfsSum(TreeNode *root) {
        if (root == nullptr) return 0;

        int leftPath = max(0, dfsSum(root->left));
        int rightPath = max(0, dfsSum(root->right));

        int path = root->val + leftPath + rightPath;
        maxSum = max(maxSum, path);

        return root->val + max(leftPath, rightPath);
    }
    int maxPathSum(TreeNode* root) {
        dfsSum(root);
        return maxSum;
    }
};
