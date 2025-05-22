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
    // Helper to compute max path sum and update global maximum
    int maxPathSumHelper(TreeNode* root, int& maxi) {
        if (root == nullptr) return 0;

        // Compute max sum from left and right subtrees, ignoring negatives
        int lsum = max(0, maxPathSumHelper(root->left, maxi));
        int rsum = max(0, maxPathSumHelper(root->right, maxi));

        // Update global maximum with current node as the highest point
        maxi = max(maxi, lsum + rsum + root->val);

        // Return max sum including current node and one child
        return root->val + max(lsum, rsum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;

        // Start recursion to compute path sum
        maxPathSumHelper(root, maxi);

        // Return the maximum path sum found
        return maxi;
    }
};