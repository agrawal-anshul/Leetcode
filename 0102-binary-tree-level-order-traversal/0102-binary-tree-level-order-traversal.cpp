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
    vector<vector<int>> helper(TreeNode* root, vector<vector<int>>res){
        if(root == nullptr)return res;
        
        queue<TreeNode*>q;
        q.push(root);
        q.push(nullptr); //level marker
        
        vector<int>level;

        while(!q.empty()){
            TreeNode* front = q.front(); 
            q.pop();

            if(front==nullptr){
                // Finished 1 level
                res.push_back(level);
                level.clear();
                
                // Only add another nullptr if theres mpde nodes to process
                if(!q.empty()){
                    q.push(nullptr);
                }
            }
            else{
                level.push_back(front->val);
                // Enqueue non-null children
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
        }
        return res;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        return helper(root,res);
    }
};