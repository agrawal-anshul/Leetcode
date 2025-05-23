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
    // Using nullptr as level marker
    vector<vector<int>> helper1(TreeNode* root, vector<vector<int>>&res){
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
                
                // Only add another nullptr if theres nodes to process
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

    // Without using nullptr as level marker
    vector<vector<int>> helper2(TreeNode* root, vector<vector<int>>&res){
        if(!root)return res;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            int levelSize = q.size();
            vector<int>level;

            for(int i=0; i<levelSize; i++){
                TreeNode* front = q.front();
                q.pop();
                
                level.push_back(front->val);
                
                if(front->left)q.push(front->left);
                if(front->right)q.push(front->right);
            }
            res.push_back(level);
        }
        return res;
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        return helper1(root,res);
        // return helper2(root,res);
    }
};