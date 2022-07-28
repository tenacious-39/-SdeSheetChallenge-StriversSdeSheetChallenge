/************************************************************

    Following is the Binary Tree node structure
    
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
#include<bits/stdc++.h>
class NodeValue{
    public:
    int maxNode, minNode, maxSize;
    
    NodeValue(int _maxi, int _mini, int _size){
        this->maxNode = _maxi;
        this->minNode = _mini;
        this->maxSize = _size;
    }
};
NodeValue f(TreeNode<int>* root){
    if(!root) return  NodeValue(INT_MIN, INT_MAX, 0);
    
    auto left = f(root->left);
    auto right = f(root->right);
    if(left.maxNode < root->data && root->data < right.minNode){
        return NodeValue(max(root->data,right.maxNode), min(root->data,left.minNode), left.maxSize+right.maxSize+1);
    }
    return NodeValue(INT_MAX,INT_MIN, max(left.maxSize,right.maxSize));
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    return f(root).maxSize;
}
