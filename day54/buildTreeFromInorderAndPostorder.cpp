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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> inorderMap;
        int n = inorder.size();
        for(int i=0;i<n;i++) inorderMap[inorder[i]] = i;
        TreeNode* root = buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inorderMap);
        return root;
    }
    TreeNode* buildTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder,
                       int inStart, int inEnd, map<int,int> &inorderMap){
        if(postStart > postEnd or inStart > inEnd) return NULL;
        TreeNode *root = new TreeNode(postorder[postEnd]);
        
        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot-inStart;
        root->left = buildTree(postorder, postStart, postStart+numsLeft-1, inorder, inStart, inRoot-1, inorderMap);
        root->right = buildTree(postorder,  postStart+numsLeft, postEnd-1, inorder, inRoot+1, inEnd, inorderMap);
        return root;
    }
};
