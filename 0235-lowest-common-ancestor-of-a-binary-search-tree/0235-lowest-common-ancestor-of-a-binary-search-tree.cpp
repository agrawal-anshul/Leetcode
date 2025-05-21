/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* lowestCommonAncestor_BST(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        
        // If both nodes are greater than root, LCA lies in right subtree
        if (p->val > root->val and q->val > root->val) {
            return lowestCommonAncestor_BST(root->right, p, q);
        }
        // If both nodes are less than root, LCA lies in left subtree
        if (p->val < root->val and q->val < root->val) {
            return lowestCommonAncestor_BST(root->left, p, q);
        }

        // Either root is one of p or q, or p and q lie on either side → root is LCA
        return root;
    }

    TreeNode* lowestCommonAncestor_BTree(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr or root == p or root == q) return root;

        TreeNode* left = lowestCommonAncestor_BTree(root->left, p, q);
        TreeNode* right = lowestCommonAncestor_BTree(root->right, p, q);

        if (left != nullptr and right != nullptr) return root;
        return (left != nullptr) ? left : right;
    }

    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // return lowestCommonAncestor_BTree(root,p,q);
        return lowestCommonAncestor_BST(root,p,q);
    }
};