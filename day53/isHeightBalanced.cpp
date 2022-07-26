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
int findHeight(BinaryTreeNode<int>* node){
        if(node == NULL ) return 0;

        int lh = findHeight(node->left);
        int rh = findHeight(node->right);

        if(lh == -1 or rh == -1) return -1;
        if(abs(lh-rh) > 1 ) return -1;
        return 1+max(lh,rh);
    }
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return findHeight(root) == -1? false : true;
}
