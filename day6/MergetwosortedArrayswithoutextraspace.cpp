class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n!= 0 && m != 0){
            for(int i = 0; i < m; i++){
                if(nums1[i] > nums2[0]){
                   // cout << "i = " << i << "\n";
                    int tmp = nums1[i];
                    nums1[i] = nums2[0];
                    nums2[0] = tmp;
                    int ele = nums2[0];
                    for(int j = 1; j < n; j++){
                        if(ele > nums2[j]){
                            nums2[j-1] = nums2[j];
                             if(j == n-1) nums2[j] = ele;
                        } else{
                            nums2[j-1] = ele;
                            break;
                        }
                    }
                }
            }

            for(int i = m; i < m+n; i++){
                nums1[i] = nums2[i-m];
            }
        }else if(m == 0 && n != 0){
            for(int i = m; i < m+n; i++){
                nums1[i] = nums2[i-m];
            }
        }
    }
};
