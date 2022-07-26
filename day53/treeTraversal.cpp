/************************************************************

    Following is the Binary Tree node structure:

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


************************************************************/
void traverse(BinaryTreeNode<int> *node, vector<vector<int>> &path){
    if(node == NULL) return;
    
    path[1].push_back(node->data);
    traverse(node->left, path);
    path[0].push_back(node->data);
    traverse(node->right, path);
    path[2].push_back(node->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<vector<int>> path(3);
    traverse(root, path);
    return path;
}
