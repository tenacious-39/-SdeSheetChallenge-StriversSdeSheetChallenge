/************************************************************

    Following is the Binary Tree node structure:
    
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
void getLeftNodes(TreeNode<int>* node, vector<int> &ans){
    if(node->left == NULL and node->right == NULL) return;
    ans.push_back(node->data);
    if(node->left) getLeftNodes(node->left, ans);
    else getLeftNodes(node->right, ans);
}
void getLeafNodes(TreeNode<int>* node, vector<int> &ans){
    if(node->left == NULL and node->right == NULL){
        ans.push_back(node->data);
        return;
    }
    if(node->left) getLeafNodes(node->left, ans);
    if(node->right) getLeafNodes(node->right, ans);
}
void getRightNodes(TreeNode<int>* node, stack<int> &st){
    if(node->left == NULL and node->right == NULL) return;
    st.push(node->data);
    if(node->right) getRightNodes(node->right, st);
    else getRightNodes(node->left, st);
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root == NULL) return ans;
    ans.push_back(root->data);
    //Left nodes:
    if(root->left) getLeftNodes(root->left, ans);
    
    //getLeafNode:
    if(root->left or root->right){ 
        getLeafNodes(root, ans);
    }
    
    //getRightNodes:
    
    if(root->right) {
        stack<int> st;
        getRightNodes(root->right, st);
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
    }
    return ans;
}
