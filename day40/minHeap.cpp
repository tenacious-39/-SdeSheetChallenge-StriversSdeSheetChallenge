int left(int ind){ return 2*ind+1;}
int right(int ind){return 2*ind+2;}
int parent(int ind){ return (ind-1)/2;}
void heapifyUp(vector<int> &heap){
    int ind = heap.size()-1;
    while(parent(ind) >= 0 and heap[parent(ind)] > heap[ind]){
        swap(heap[parent(ind)], heap[ind]);
        ind = parent(ind);
    }
}
void heapifyDown(vector<int> &heap){
    int ind = 0;
    int n = heap.size();
    while(left(ind) < n){
        int smallChildIndex = left(ind);
        if(right(ind) < n && heap[right(ind)] < heap[left(ind)])
            smallChildIndex = right(ind);
        if(heap[ind] < heap[smallChildIndex]) break;
        else{
            swap(heap[ind], heap[smallChildIndex]);
        }
        ind = smallChildIndex;
    }
}
void insert(vector<int> &heap, int key){
    heap.push_back(key);
    if(heap.size() > 1) heapifyUp(heap);
}
void deleteRoot(vector<int> &heap){
    int n = heap.size();
    swap(heap[0], heap[n-1]);
    heap.pop_back();
    heapifyDown(heap);
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> heap;
    vector<int> ans;
    for(auto it : q){
        if(it[0] == 0){
            insert(heap, it[1]);
        } else{
            ans.push_back(heap[0]);
            deleteRoot(heap);
        }
    }
    //for(auto it : ans) cout << it << "\n";
    return ans;
}



/////////////////////////////// Recursive Code://///////////////////////////////////////////////////
int left(int ind){ return 2*ind+1;}
int right(int ind){return 2*ind+2;}
int parent(int ind){ return (ind-1)/2;}
void heapifyUp(vector<int> &heap, int ind){
    //int ind = heap.size()-1;
    //cout << "parent = " << parent(ind) << "\n";
    if(ind != 0 && parent(ind) >= 0){
        
        if(heap[parent(ind)] < heap[ind]) return;

         swap(heap[parent(ind)], heap[ind]);
         heapifyUp(heap, parent(ind));
    }
}
void heapifyDown(vector<int> &heap, int ind){
    //int ind = 0;
    int n = heap.size();
    if(left(ind) >= n) return;
        int smallChildIndex = left(ind);
        if(right(ind) < n && heap[right(ind)] < heap[left(ind)])
            smallChildIndex = right(ind);
        if(heap[ind] < heap[smallChildIndex]) return;
        else{
            swap(heap[ind], heap[smallChildIndex]);
            ind = smallChildIndex;
            heapifyDown(heap, smallChildIndex);
        }
        
}
void insert(vector<int> &heap, int key){
    heap.push_back(key);
    //cout << "inserted\n";
    if(heap.size() > 1) heapifyUp(heap, heap.size()-1);
}
void deleteRoot(vector<int> &heap){
    int n = heap.size();
    swap(heap[0], heap[n-1]);
    heap.pop_back();
    heapifyDown(heap, 0);
}
vector<int> minHeap(int n, vector<vector<int>>& q) {
    // Write your code here.
    vector<int> heap;
    vector<int> ans;
    for(auto it : q){
        if(it[0] == 0){
            insert(heap, it[1]);
        } else{
            ans.push_back(heap[0]);
            deleteRoot(heap);
        }
    }
    //for(auto it : ans) cout << it << "\n";
    //ans.push_back(1);
    return ans;
}

