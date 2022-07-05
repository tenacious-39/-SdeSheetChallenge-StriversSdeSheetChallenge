// brute force:
Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        map<Node*, Node*> mp;
        Node *newHead = new Node(head->val);
        mp[NULL] = NULL;
        mp[head] = newHead;
        Node* cur = head->next;
        while(cur){
            Node *n = new Node(cur->val);
            mp[cur] = n;
            cur = cur->next;
        }
        
        cur = head;
        while(cur){
            mp[cur]->next = mp[cur->next];
            mp[cur]->random = mp[cur->random];
            cur = cur->next;
        }
        return newHead;
    }


// Optimized:
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *iter = head, *front = head;
        
        // Deep copy of nodes:
        while(iter){
            front = iter->next;
            Node *copy = new Node(iter->val);
            iter->next = copy;
            copy->next = front;
            iter = front;
        }
        
        // set random pointers;
        iter = head;
        while(iter){
            if(iter->random){
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        
        //restore original Linked List:
        
        Node *pseudoHead = new Node(0);
        Node* copy = pseudoHead;
        iter = head;
        while(iter){
            copy->next = iter->next;
            front = iter->next->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        }
        return pseudoHead->next;
    }
};
