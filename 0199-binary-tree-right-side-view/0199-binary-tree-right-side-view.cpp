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
    // Intuition and Key Observations:
    // - We are asked to view the binary tree from the right side. At each level, only the
    // rightmost node should be visible.
    // - This is essentially a level-order traversal (BFS), but instead of collecting all
    // nodes at each level, we only store the last node processed at that level.
    vector<int> rightSideViewHelper(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        // Traverse level by level
        while (!q.empty()) {
            int levelSize = q.size();
            TreeNode* curr = nullptr;

            // Traverse all nodes at current level
            for (int i = 0; i < levelSize; i++) {
                curr = q.front();
                q.pop();

                // Add left child to queue if exists
                if (curr->left != nullptr) {
                    q.push(curr->left);
                }

                // Add right child to queue if exists
                if (curr->right != nullptr) {
                    q.push(curr->right);
                }
            }

            // After the loop, 'curr' is the rightmost node of the current level
            result.push_back(curr->val);
        }

        return result;
    }

    vector<int> rightSideView(TreeNode* root) {
        return rightSideViewHelper(root);
    }
};