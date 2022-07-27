/*************************************************************

    Following is the Binary Tree node structure

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode < T > *left;
        BinaryTreeNode < T > *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
void check(BinaryTreeNode < int > *node){
    if(!node->left and !node->right) return;
    if(node->left) check(node->left);
    if(node->right) check(node->right);
    int sum = 0;
    if(node->left) sum += node->left->data;
    if(node->right) sum += node->right->data;
    if(sum < node->data){
        int dif = node->data-sum;
        if(node->left) node->left->data += dif;
        else node->right->data += dif;
        if(node->left) check(node->left);
        if(node->right) check(node->right);
    } else if(sum > node->data){
        node->data = sum;      
    }
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    if(root == NULL) return;
    check(root);
}  
