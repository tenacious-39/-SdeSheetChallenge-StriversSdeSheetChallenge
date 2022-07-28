/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void findFloor(TreeNode<int> *node, int x, int &maxi){
    if(node == NULL) return;
    if(node->val <= x){
        maxi = max(maxi, node->val);
    }
    if(x <= node->val) findFloor(node->left, x, maxi);
    else findFloor(node->right, x, maxi);
}
int floorInBST(TreeNode<int> * root, int X)
{
    // Write your code here.
    
    int maxi = INT_MIN;
    findFloor(root, X, maxi); return maxi;
}
