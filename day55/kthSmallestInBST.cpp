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
void findSmall(TreeNode<int> *node, int &cnt, int k, int &ans){
    
    if(node == NULL) return;
    //cout << "node = " << node->data << " cnt = " << cnt << "\n";
    if(cnt == k) ans = node->data;
    findSmall(node->left, cnt, k, ans);
    //cout << "anode = " << node->data << " cnt = " << cnt << "\n";
    if(cnt == k) ans = node->data;
    cnt++;
    findSmall(node->right, cnt, k, ans);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int ans = -1;
    int cnt = 1;
    findSmall(root, cnt, k, ans); return ans;
}
