 void printSums(vector<int> &arr, int n, int idx, int sum, vector<int> &ans){
        if(idx == n){
            ans.push_back(sum);
            return;
        }
        
        printSums(arr, n, idx+1, sum+arr[idx], ans);
        printSums(arr, n, idx+1, sum, ans);
    }

vector<int> subsetSums(vector<int> arr, int n)
    {
        // Write Your Code here
        int sum = 0;
        vector<int> ans;
        printSums(arr, n, 0, sum, ans);
        return ans;
    }
