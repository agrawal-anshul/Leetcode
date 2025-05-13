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
    vector<int> inorderTraversalIterative(TreeNode* root){
        vector<int>res;
        if(root == NULL){
            return res;
        }
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(!st.empty() || curr != NULL){
            if(curr != NULL){
                // Go as left as possible
                // Keep moving left and pushing the curr(root) to the stack.
                st.push(curr);
                curr = curr->left;
            }
            else{
                // Backtrack and visit the node
                // If curr is null, pop from stack and print and move to the right.
                curr = st.top();
                st.pop();

                res.push_back(curr->val); 

                // Move to the right subtree
                curr = curr->right;
            }
        }
        return res;
    }
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        return inorderTraversalIterative(root);
    }
};