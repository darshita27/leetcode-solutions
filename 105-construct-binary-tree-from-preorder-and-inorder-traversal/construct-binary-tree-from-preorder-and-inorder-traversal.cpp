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
int search(vector<int>&inorder, int value,int left, int right){
    for(int i=left;i<=right;i++){
        if(inorder[i]==value) return i;
    }
    return -1;
}
TreeNode* buildTreeRec(vector<int>&inorder, vector<int>&preOrder,int &preIndex,int left, int right){
    if(left>right) return NULL;
        int rootVal= preOrder[preIndex];
        preIndex++;
        TreeNode* root= new TreeNode(rootVal);
        int index= search(inorder, rootVal, left, right);
        root->left= buildTreeRec(inorder, preOrder,preIndex,left, index-1);
        root->right= buildTreeRec(inorder, preOrder,preIndex,index+1, right);
        return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int preIndex=0;
    TreeNode* root= buildTreeRec(inorder, preorder, preIndex, 0, preorder.size()-1);
    return root;
    }
};