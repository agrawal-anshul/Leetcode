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
    int levelOrderTraversal(TreeNode* root){
        if(root == NULL)return 0;

        // inintialise with root->val for in case nodes are all negative then maxSum = 0 will always be the greatest node. for e,g, maxSum = 0 > -100.
        int maxSum = root->val;
        int currLevel = 0;
        int answerLevel  = 1;
        
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelSize = q.size();
            int levelSum = 0;
            currLevel++;
            for(int i=0; i < levelSize ; i++){
                TreeNode* front = q.front();
                q.pop();

                levelSum += front->val;

                if(front->left){q.push(front->left);}
                if(front->right){q.push(front->right);}
            }
            if(maxSum < levelSum){
                    answerLevel = currLevel;
                }
                maxSum = max(maxSum, levelSum);
        }
        return answerLevel;
    }
    int maxLevelSum(TreeNode* root) {
        return levelOrderTraversal(root);
    }
};