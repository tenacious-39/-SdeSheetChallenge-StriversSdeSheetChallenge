Node* merge(Node *a, Node *b){
        Node *tmp = new Node(0);
        Node *res = tmp;
        while(a && b){
            if(a->data < b->data){
                tmp->bottom = a;
                tmp = tmp->bottom;
                a = a->bottom;
            } else{
                tmp->bottom = b;
                tmp = tmp->bottom;
                b = b->bottom;
            }
        }
        if(a) tmp->bottom = a;
        else tmp->bottom = b;
        
        return res->bottom;
    }
Node *flatten(Node *root)
{
   // Your code here
   if(root == NULL or root->next == NULL) return root;
   root->next = flatten(root->next);
   root = merge(root, root->next);
   return root;
}
