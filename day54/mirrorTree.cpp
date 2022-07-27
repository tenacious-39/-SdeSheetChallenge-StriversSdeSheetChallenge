void Mirror(Node* root){
        if(root == NULL) return;
        swap(root->left, root->right);
        if(root->left) Mirror(root->left);
        if(root->right) Mirror(root->right);
    }
    void mirror(Node* node) {
        // code here
        if(node == NULL) return;
        Mirror(node);
    }
