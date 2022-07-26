/*************************************************************
 
    Following is the Binary Tree node structure.

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
    };

*************************************************************/

vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
    queue<pair<BinaryTreeNode<int>*, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        mp[it.second] = it.first->data;
        if(it.first->left != NULL){
            q.push({it.first->left, it.second-1});
        }
        if(it.first->right != NULL){
            q.push({it.first->right, it.second+1});
        }
    }
    vector<int> ans;
    for(auto it : mp) ans.push_back(it.second);
    return ans;
}
