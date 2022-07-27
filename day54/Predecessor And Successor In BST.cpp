/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

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

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    BinaryTreeNode<int>* pred = new BinaryTreeNode<int>(-1);     BinaryTreeNode<int> *succ = new BinaryTreeNode<int>(-1);
    while(root){
        if(root->data == key) break;
        if(key > root->data){
            pred = root;
            root = root->right;
        } else{
            succ= root;
            root = root->left;
        }
    }
    int p = pred->data, s = succ->data;
    pred = root->left; succ = root->right;
    if(pred){
        p = pred->data;
        while(pred->right){
            pred = pred->right;
            p = pred->data;
        }
    }
    if(succ){
        s = succ->data;
        while(succ->left){
            succ = succ->left;
            s = succ->data;
        }
    }
    pair<int,int> ans = make_pair(p, s);
    return ans;
}
