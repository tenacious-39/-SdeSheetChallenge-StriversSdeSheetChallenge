/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorder(TreeNode* node, vector<int> &ans){
    if(node == NULL) return;
    
    inorder(node->left, ans);
    ans.push_back(node->data);
    inorder(node->right, ans);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> ans;
    inorder(root, ans);
    return ans;
}
