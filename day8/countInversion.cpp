void merge(long long arr[], int n, long long &ans, long long tmp[], int low, int mid, int high){
    
    int i = low, j = mid, k = low;
    while(i <= mid-1 && j <= high){
        if(arr[i] <= arr[j]) tmp[k++] = arr[i++];
        else {
            ans += (mid-i);
            tmp[k++] = arr[j++];
        }
    }
    
    while(i <= mid-1){
        tmp[k++] = arr[i++];
    }
    while(j <= high){
        tmp[k++] = arr[j++];
    }
    for(int i = low; i <= high; i++) arr[i] = tmp[i];
    
}

void mergeSort(long long arr[], int n, long long &ans, long long tmp[], int low, int high){
    //cout << "ms\n";
    if(low < high){
        int mid = (low+high)/2;
        mergeSort(arr, n, ans, tmp, low, mid);
        mergeSort(arr, n, ans, tmp, mid+1, high);
        
        merge(arr, n, ans, tmp, low, mid+1, high);
    }
}
long long getInversions(long long *a, int n){
    // Write your code here.
    long long ans = 0;
    long long arr[n];
    for(int i = 0; i < n; i++) arr[i] = a[i];
    long long tmp[n];
    int low = 0, high = n-1;
    mergeSort(arr, n, ans, tmp, low, high);
    return ans;
}
