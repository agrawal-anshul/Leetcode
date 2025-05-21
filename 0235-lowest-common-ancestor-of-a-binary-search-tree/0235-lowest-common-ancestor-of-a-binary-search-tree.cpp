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
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == p || root == q || root == nullptr)return root;
        
        if(p->val > root->val and q->val > root->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        if(p->val < root->val and q->val < root->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if (left != nullptr and right != nullptr) return root;
        return (left != nullptr) ? left : right;
    }
};