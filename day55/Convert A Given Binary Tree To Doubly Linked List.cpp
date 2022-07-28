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
void f(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &listHead, BinaryTreeNode<int>* &prev){
    if(!root) return;
    f(root->left, listHead,prev);
    if(!prev) listHead = root;
    else{
        root->left=prev; prev->right = root;
    }
    prev = root; f(root->right,listHead, prev);
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int>* listHead = NULL, *prev = NULL;
    f(root, listHead, prev);
    return listHead;
}
