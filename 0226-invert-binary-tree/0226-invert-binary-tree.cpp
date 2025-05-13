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
    TreeNode* invertTreeRecursive(TreeNode* root) {
        if(root == NULL){
            return root;
        }
        TreeNode* invertedLeft =  invertTree(root->left);
        TreeNode* invertedright =  invertTree(root->right);
        root->left = invertedright;
        root->right = invertedLeft;
        return root;
    }
    TreeNode* invertTreeIterative(TreeNode* root){
        if(root == NULL){
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            // Swap left and right subtree
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;

            if(curr->left != NULL){q.push(curr->left);}
            if(curr->right != NULL){q.push(curr->right);}

        }
        return root;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        // return invertTreeRecursive(root);
        return invertTreeIterative(root);
    }
};