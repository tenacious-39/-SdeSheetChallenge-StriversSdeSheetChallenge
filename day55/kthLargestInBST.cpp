/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void findSmall(TreeNode<int> *node, int &cnt, int k, int &ans){
    
    if(node == NULL) return;
    if(cnt == k) ans = node->data;
    findSmall(node->left, cnt, k, ans);
    if(cnt == k) ans = node->data;
    cnt++;
    findSmall(node->right, cnt, k, ans);
}
void countNodes(TreeNode<int>* root, int &cnt){
    if(!root) return;
    cnt++;
    countNodes(root->left, cnt);
    countNodes(root->right, cnt);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int nodeCount =0;
    countNodes(root, nodeCount);
    int ans = -1;
    int cnt = 1;
    findSmall(root, cnt, nodeCount-k+1, ans); return ans;
}
