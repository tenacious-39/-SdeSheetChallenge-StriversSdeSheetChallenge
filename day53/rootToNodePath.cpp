/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/
#include<bits/stdc++.h>
bool findPath(TreeNode<int> *node, int x, vector<int> &ans){
    if(node == NULL) return false;
    ans.push_back(node->data);
    if(node->data == x){
        return true;
    }
    
    if(findPath(node->left,x,ans) or findPath(node->right,x,ans)){
        return true;
    } else{ ans.pop_back(); return false;}
} 
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> ans;
    if(root == NULL) return ans;
    findPath(root, x, ans);
     return ans;
}
