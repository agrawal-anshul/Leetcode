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
    vector<int>preorderTraversalIterative(TreeNode* root){
        vector<int>res;
        if(root == NULL){
            return res;
        }
        
        stack<TreeNode*>st;
        TreeNode* curr = root;
        st.push(curr);

        while(!st.empty()){
            curr = st.top();
            st.pop();
            res.push_back(curr->val);
            if(curr->right)st.push(curr->right);
            if(curr->left)st.push(curr->left);
        }
        return res;
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        return preorderTraversalIterative(root);
    }
};