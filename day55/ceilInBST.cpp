/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/
void findceil(BinaryTreeNode<int> *node, int x, int &mini){
    if(node == NULL) return;
    if(node->data >= x){
        mini = min(mini, node->data);
    }
    if(x <= node->data) findceil(node->left, x, mini);
    else findceil(node->right, x, mini);
}
int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    int mini = INT_MAX;
    findceil(node, x, mini); return mini == INT_MAX? -1 : mini;
}
