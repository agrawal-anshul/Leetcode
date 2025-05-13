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
    // Iterative Postorder: Left → Right → Root using one stack
    vector<int> postorderTraversalIterative(TreeNode* root) {
        vector<int> result;

        if (root == nullptr) {
            return result;
        }

        stack<TreeNode*> st;
        TreeNode* curr = root;
        TreeNode* lastVisited = nullptr;

        while (!st.empty() or curr != nullptr) {
            if (curr != nullptr) {
                // Traverse left subtree
                st.push(curr);
                curr = curr->left;
            } else {
                TreeNode* peekNode = st.top();

                // If right child exists and hasn't been visited yet
                if (peekNode->right != nullptr and lastVisited != peekNode->right) {
                    curr = peekNode->right;
                } else {
                    // Visit the node after left and right children are done
                    result.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }
            }
        }

        return result;
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return postorderTraversalIterative(root);
    }
};