/************************************************************

    Following is the TreeNode class structure:

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
#include<bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
    vector<int> ans;
    if(root == NULL)  return ans;
    queue<pair<TreeNode<int>*, int>> q;
    map<int, int> mp;
    q.push({root, 0});
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        if(mp.find(it.second) == mp.end()) mp[it.second] = it.first->val;
        if(it.first->left != NULL){
            q.push({it.first->left, it.second-1});
        }
        if(it.first->right != NULL){
            q.push({it.first->right, it.second+1});
        }
    }
    
    for(auto it : mp) ans.push_back(it.second);
    return ans;
}
