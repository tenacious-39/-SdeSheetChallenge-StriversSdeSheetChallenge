/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void inorder(BinaryTreeNode<int> *node, vector<int> &ans){
    if(!node) return;
    inorder(node->left, ans);
    ans.push_back(node->data);
    inorder(node->right, ans);
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    if(root == NULL) return true;
    vector<int> ans;
    inorder(root, ans);
    for(int i=1;i<ans.size();i++){
        if(ans[i] < ans[i-1]) return false;
    } return true;
}
