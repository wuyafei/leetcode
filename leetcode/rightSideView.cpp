/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> rt;
        if(!root) return rt;
        queue<TreeNode*> q1;
        queue<int> q2;
        q1.push(root);
        q2.push(1);
        while(!q1.empty()){
            TreeNode* pTmp=q1.front();
            q1.pop();
            int iTmp=q2.front();
            q2.pop();
            if(q2.empty() || iTmp!=q2.front()){
                rt.push_back(pTmp->val);
            }
            if(pTmp->left){
                q1.push(pTmp->left);
                q2.push(iTmp+1);
            }
            if(pTmp->right){
                q1.push(pTmp->right);
                q2.push(iTmp+1);
            }
        }
        return rt;
    }
};