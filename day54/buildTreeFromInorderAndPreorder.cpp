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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> inorderMap;
        int n = inorder.size();
        for(int i=0;i<n;i++) inorderMap[inorder[i]] = i;
        TreeNode* root = buildTree(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inorderMap);
        return root;
    }
    TreeNode* buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder,
                       int inStart, int inEnd, map<int,int> &inorderMap){
        if(preStart > preEnd or inStart > inEnd) return NULL;
        TreeNode *root = new TreeNode(preorder[preStart]);
        
        int inRoot = inorderMap[root->val];
        int numsLeft = inRoot-inStart;
        root->left = buildTree(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inorderMap);
        root->right = buildTree(preorder,  preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inorderMap);
        return root;
    }
};
