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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder, int pi, int pj, vector<int>& inorder, int ii, int ij){
        if(pi>pj)
            return NULL;
        if(pi==pj)
            return new TreeNode(preorder[pi]);
        int i;
        for(i=ii;i<=ij;i++)
            if(preorder[pi]==inorder[i])
                break;
        TreeNode *tRoot=new TreeNode(preorder[pi]);
        tRoot->left=build(preorder,pi+1, pi+i-ii, inorder, ii, i-1);
        tRoot->right=build(preorder, pi+i-ii+1, pj, inorder, i+1, ij);
        return tRoot;
    }
};