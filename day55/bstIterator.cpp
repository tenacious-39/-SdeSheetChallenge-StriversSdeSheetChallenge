/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<stack>
class BSTiterator
{
    public:
    stack<TreeNode<int>*> st;
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        TreeNode<int> *cur = root;
        while(cur){
            st.push(cur);
            cur = cur->left;
        }
    }
    
    int next()
    {
        // write your code here
        if(st.size() == 0) return -1;
        auto node = st.top(); st.pop();
        if(node->right){
            auto cur = node->right;
            while(cur){
                st.push(cur);
                cur = cur->left;
            }
        }
        return node->data;
    }

    bool hasNext()
    {
        // write your code here
        return st.size() != 0;
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/
