class Queue {
    vector<int> q;
    int f, r, cnt;
    int n;
public:
    Queue() {
        // Implement the Constructor
        q = vector<int>(5000, 0);
        f = r = 0;
        cnt = 0;
        n = 5000;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (cnt == 0);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(cnt < n){
            cnt++;
            q[r%n] = data;
            r++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        int ans = -1;
        if(cnt != 0){
            cnt--;
            ans = q[f%n];
            q[f%n] = -1;
            f++;
        } return ans;
    }

    int front() {
        // Implement the front() function
        if(cnt!= 0) return q[f%n];
        else return -1;
    }
};
