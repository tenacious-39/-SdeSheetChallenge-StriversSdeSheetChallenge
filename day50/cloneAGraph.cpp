/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        unordered_map<Node*, Node*> mpp;
        Node* copy = new Node(node->val, vector<Node*>());
        mpp[node] = copy;
       queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* n = q.front();
            q.pop();
            for(auto it : n->neighbors){
                if(mpp.find(it) == mpp.end()){
                    mpp[it] = new Node(it->val, vector<Node*>());
                    q.push(it);
                }
                mpp[n]->neighbors.push_back(mpp[it]);
            }
        } return copy;
    }
};
