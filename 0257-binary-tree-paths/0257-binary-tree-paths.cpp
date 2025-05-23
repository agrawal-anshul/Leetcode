class Solution {
public:
    void binaryTreePathsHelper(TreeNode* root, vector<string>& res, string str1) {
        if (root == nullptr) {
            return;
        }

        // Append current node's value to the path string
        if (!str1.empty()) {
            str1 += "->";
        }
        str1 += to_string(root->val);

        // If this is a leaf node, add the path to the result
        if (root->left == nullptr and root->right == nullptr) {
            res.push_back(str1);
            return;
        }

        // Recur for left and right children
        if (root->left != nullptr) {
            binaryTreePathsHelper(root->left, res, str1);
        }
        if (root->right != nullptr) {
            binaryTreePathsHelper(root->right, res, str1);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        string str1 = "";
        binaryTreePathsHelper(root, res, str1);
        return res;
    }
};