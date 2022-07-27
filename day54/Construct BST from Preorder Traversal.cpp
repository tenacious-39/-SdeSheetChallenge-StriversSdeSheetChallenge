/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include<bits/stdc++.h>
TreeNode<int>* buildBST(vector<int> &arr, int start, int end){
    if(start > end) return NULL;
    int mid = (start+end)>>1;
    TreeNode<int>* root = new TreeNode<int>(arr[mid]);
    root->left = buildBST(arr, start, mid-1);
    root->right = buildBST(arr, mid+1, end);
    return root;
}
TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int n = preOrder.size();
    if(n == 0) return NULL;
    sort(preOrder.begin(), preOrder.end());
    return buildBST(preOrder, 0, n-1);
}
