/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
#include<bits/stdc++.h>
bool findSum(BinaryTreeNode<int> *root, int k, unordered_map<int,int> &mp){
    if(!root) return false;
    int target = k-root->data;
    if(mp.find(target) != mp.end()) return true;
    mp[root->data]++;
    if(findSum(root->left, k, mp) or findSum(root->right,k,mp))
        return true;
    return false;
}
bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    unordered_map<int,int> mp;
    return findSum(root, k, mp);
}
