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
    int diameterfn(TreeNode* node, int& diameter){
        if(node == NULL){
            return 0;
        }
        int left = diameterfn(node->left, diameter);
        int right = diameterfn(node->right, diameter);
        diameter = max(diameter, left + right);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxDiameter = 0;
        diameterfn(root, maxDiameter);
        return maxDiameter;
    }
};