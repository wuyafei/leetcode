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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> rt;
        if(!root) return rt;
        queue<TreeNode*> tq;
        tq.push(root);
        queue<int> iq;
        iq.push(1);
        int pre=0;
        vector<int> v;
        while(!iq.empty()){
            TreeNode* tp=tq.front();
            tq.pop();
            int level=iq.front();
            iq.pop();
            if(level!=pre && !v.empty()){
                if(pre%2==0){
                    reverse(v.begin(), v.end());
                    rt.push_back(v);
                }
                else
                    rt.push_back(v);
                v.clear();
                pre=level;
            }
            v.push_back(tp->val);
            if(tp->left){
                tq.push(tp->left);
                iq.push(level+1);
            }
            if(tp->right){
                tq.push(tp->right);
                iq.push(level+1);
            }
        }
        if(pre%2==0){
            reverse(v.begin(), v.end());
            rt.push_back(v);
        }
        else
            rt.push_back(v);
        return rt;
        
    }
};