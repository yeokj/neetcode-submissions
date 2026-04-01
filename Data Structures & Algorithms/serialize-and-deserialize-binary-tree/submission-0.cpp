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

class Codec {
public:
    void dfsS(TreeNode *root, string &data) {
        if (root == nullptr) {
            data += "N,";
            return;
        }
        else {
            data += (to_string(root->val));
            data += ',';
        }
        dfsS(root->left, data);
        dfsS(root->right, data);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }
        string data;
        dfsS(root, data);

        return data;
    }

    int i = 0;

    TreeNode* dfsD(vector<string> &tokens) {
        if (tokens[i] == "N") {
            ++i;
            return nullptr;
        }

        TreeNode *node = new TreeNode(stoi(tokens[i]));
        ++i;
        node->left = dfsD(tokens);
        node->right = dfsD(tokens);

        return node;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return nullptr;
        }
        stringstream ss(data);
        vector<string> tokens;
        string token;
        while (getline(ss, token, ',')) {
            if (!token.empty()) {
                tokens.push_back(token);
            }
        }

        i = 0;
        TreeNode *root = dfsD(tokens);

        return root;
    }
};
