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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;
        }

        int low = min(p->val, q->val);
        int high = max(p->val, q->val);
        TreeNode *node = root;

        while (node != nullptr) {
            int nVal = node->val;

            if (nVal < low) {
                node = node->right;
            }
            else if (nVal > high) {
                node = node->left;
            }
            else {
                return node;
            }
        }
        return nullptr;
    }
};
