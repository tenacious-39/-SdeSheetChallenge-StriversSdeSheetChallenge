struct node{
  int key, val, cnt;
    node* prev, *next;
    node(int _key, int _val){
        key = _key;
        val = _val;
        cnt = 1;
    }
};

struct List{
    int size;
    node* head, *tail;
    List(){
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }
    
    void addNode(node* n){
        node* dummy = head->next;
        n->next = dummy;
        n->prev = head;
        head->next = n;
        dummy->prev = n;
        size++;
    }
    
    void deleteNode(node* n){
        node* delnext = n->next;
        node* delprev = n->prev;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};
class LFUCache {
public:
    LFUCache(int capacity) {
        
    }
    
    int get(int key) {
        
    }
    
    void put(int key, int value) {
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
