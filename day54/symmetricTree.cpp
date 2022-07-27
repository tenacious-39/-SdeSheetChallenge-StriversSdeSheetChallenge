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
    bool isSymmetric(TreeNode* left, TreeNode* right){
    if(!left or !right) return left==right;
    if(left->val != right->val) return false;
    
    return isSymmetric(left->left, right->right) and isSymmetric(left->right, right->left);
}

    bool isSymmetric(TreeNode* root) {
        return root==NULL or isSymmetric(root->left, root->right);
    }
};
