/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<queue>
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root == NULL) return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while(!q.empty()){
        int size = q.size();
        BinaryTreeNode<int>* prev = NULL;
        for(int i=0;i<size;i++){
            auto node = q.front();
            q.pop();
            if(prev == NULL){
                prev = node;
            } else{
                prev->next = node;
                prev=node;
            }
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
}
