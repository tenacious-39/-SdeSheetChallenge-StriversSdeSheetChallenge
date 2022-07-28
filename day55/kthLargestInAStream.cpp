#include<queue>
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int kth;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
        kth = k;
        for(auto it : arr){
            pq.push(it);
            if(pq.size() > kth) pq.pop();
        }
    }

    void add(int num) {
        // Write your code here.
        pq.push(num);
        if(pq.size()>kth){
               pq.pop();
       }
    }

    int getKthLargest() {
       // Write your code here.
        return pq.top();
    }

};
