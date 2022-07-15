// Stack class.
class Stack {
    vector<int> stack;
    int size;
    int cap;
public:
    
    Stack(int capacity) {
        // Write your code here.
        stack = vector<int>(capacity, 0); 
        size = -1;
        cap = capacity;
    }

    void push(int num) {
        // Write your code here.
        stack[++size] = num;
    }

    int pop() {
        // Write your code here.
        if(size == -1) return -1;
        size--;
        return stack[size+1];
    }
    
    int top() {
        // Write your code here.
        if(size == -1) return -1;
        return stack[size];
    }
    
    int isEmpty() {
        // Write your code here.
        return (size == -1);
    }
    
    int isFull() {
        // Write your code here.
        return (size == cap-1);
    }
    
};
