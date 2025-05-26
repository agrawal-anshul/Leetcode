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
    vector<vector<int>> zigzagLevelOrderHelper(TreeNode* root, vector<vector<int>>& res, bool& leftToRight){
        if(root == nullptr)return res;
        
        queue<TreeNode*>q;
        
        q.push(root);
        
        while(!q.empty()){
            int levelSize = q.size();
            vector<int>levels;
            for(int i=0; i<levelSize; i++){
                TreeNode* front = q.front();
                q.pop();
                levels.push_back(front->val);
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            if(leftToRight){
                reverse(levels.begin(),levels.end());
            }
            res.push_back(levels);
            leftToRight = !leftToRight;
        }
        return res;
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)return res;
        bool leftToRight = false;
        return zigzagLevelOrderHelper(root,res,leftToRight);

    }
};