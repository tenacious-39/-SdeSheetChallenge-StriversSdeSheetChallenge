class LRUCache {
public:
    class node{
        
        public:
        int key, val;
        node *prev, *next;
        node(int _key, int _val){
            key = _key;
            val = _val;
        }
    };
    
    unordered_map<int, node*> mp;
    node* head;
    node* tail;
    int cap;
    
    
    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(node *n){
        node* dummy = head->next;
        n->next = dummy;
        n->prev = head;
        dummy->prev = n;
        head->next = n;
    }
    
    void deleteNode(node* n){
        node *dummy = n->next;
        node *dprev = n->prev;
        dprev->next = dummy;
        dummy->prev = dprev;
    }
    int get(int _key) {
        if(mp.find(_key) != mp.end()){
            int ans = mp[_key]->val;
            node* n = mp[_key];
            deleteNode(n);
            node* newNode = new node(_key, ans);
            addNode(newNode);
            mp[_key] = newNode;
            return ans;
        }
        return -1;
    }
    
    void put(int _key, int value) {
        if(mp.find(_key) != mp.end()){
            deleteNode(mp[_key]);
            mp.erase(_key);
        }
        
        if(mp.size() == cap){
            int key_ = tail->prev->key; 
            deleteNode(tail->prev);
            mp.erase(key_);
        }
        
        addNode(new node(_key, value));
        mp[_key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
