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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        int m=postorder.size();
        if(n!=m) return NULL;
        return build(inorder, 0, n-1, postorder, 0, m-1);
    }
private:
    TreeNode* build(vector<int> &inorder, int ii, int ij, vector<int> &postorder, int pi, int pj){
        if(ii==ij){
            if(pi!=pj || inorder[ii]!=postorder[pi]) return NULL;
            return (new TreeNode(inorder[ii]));
        }
        if(ii>ij)
            return NULL;
        TreeNode* tn=new TreeNode(postorder[pj]);
        int i=ii;
        for(i=ii;i<=ij;i++){
           if(inorder[i]==postorder[pj]) break; 
        }
        tn->left=build(inorder, ii, i-1, postorder, pi, pi+i-ii-1);
        tn->right=build(inorder, i+1, ij, postorder, pi+i-ii, pj-1);
        return tn;
    }
};