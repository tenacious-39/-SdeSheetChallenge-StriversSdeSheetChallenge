/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        queue<pair<TreeNode*,long>> q;
        int ans = 0;
        q.push({root, 0*1LL});
        while(!q.empty()){
            int size = q.size();
            long mini = q.front().second;
            int first, last;
            for(int i=0;i<size;i++){
                long cur_ind = q.front().second-mini;
                TreeNode* node = q.front().first;
                q.pop();
                if(i == 0) first = cur_ind;
                if(i == size-1) last = cur_ind;
                if(node->left) q.push({node->left, 2*cur_ind+1});
                if(node->right) q.push({node->right, 2*cur_ind+2});
            }
            ans = max(ans, last-first+1);
        } return ans;
    }
};
