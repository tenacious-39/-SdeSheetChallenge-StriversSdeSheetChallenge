
class Solution {
    void merge(vector<int> &nums, int low, int mid, int high, int &ans){
        int j = mid;
        for(int i = low; i < mid; i++){
            while(j <= high && nums[i] > 2LL*nums[j]){
                j++;
            }
            ans += (j-mid);
        }
        
        int tmp[high-low+1];
        int i = low;
        j = mid;
        int k = 0;
        int cnt = 0;
        while(i <= mid-1 && j <= high){
            if(nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else tmp[k++] = nums[j++];
        }
        
        while(i <= mid-1) tmp[k++] = nums[i++];
        while(j <= high) tmp[k++] = nums[j++];
        
        for(int it = low; it <= high; it++){
            nums[it] = tmp[it-low];
        }
    }
    void mergeSort(vector<int> &nums, int low, int high, int &ans){
        if(low < high){
            int mid = (low+high)/2;
            mergeSort(nums, low, mid, ans);
            mergeSort(nums, mid+1, high, ans);
            
            merge(nums, low, mid+1, high, ans);
        }
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int low = 0;
        int high = n-1;
        int ans=0;
        mergeSort(nums, low, high, ans);
        return ans;
    }
};
