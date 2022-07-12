// Brute force:
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int cnt = 0;
        int a, b; 
        int len = n1+n2;
        while(i < n1 and j < n2){
            if(nums1[i] <= nums2[j]){
                
                cnt++;
                if(len%2 == 0 and cnt == len/2) a = nums1[i];
                if(cnt == (len/2)+1) b = nums1[i];
                i++;
            } else{
                
                cnt++;
                if(len%2 == 0 and cnt == len/2) a = nums2[j];
                if(cnt == (len/2)+1) b = nums2[j];
                j++;
            }
        }
        while(i < n1){
            
            cnt++;
            if(len%2 == 0 and cnt == len/2) a = nums1[i];
            if(cnt == (len/2)+1) b = nums1[i]; i++;
        }
        while(j < n2){
            cnt++;
            if(len%2 == 0 and cnt == len/2) a = nums2[j];
            if(cnt == (len/2)+1) b = nums2[j]; j++;
        }
        if(len&1) return b;
        else{
            double res = ((double)a+(double)b)/2.00;
            return res;
        }
    }
};


// Optimized approach:

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()) return findMedianSortedArrays(nums2,nums1);
        
        int n1 = nums1.size(), n2 = nums2.size();
        int low = 0, high = nums1.size();
        while(low <= high){
            int cut1 = (low+high) >> 1;
            int cut2 = (n1+n2+1)/2 - cut1;
            
            int left1 = cut1 <= 0? INT_MIN : nums1[cut1-1];
            int left2 = cut2 <= 0? INT_MIN : nums2[cut2-1];
            
            int right1 = cut1 >= n1? INT_MAX : nums1[cut1];
            int right2 = cut2 >= n2? INT_MAX : nums2[cut2];
            
            if(left1 <= right2 and left2 <= right1){
                if((n1+n2) %2 == 0){
                    return (max(left1, left2)+min(right1, right2))/2.0;
                }
                else return max(left1, left2);
            }
            else if(left1 > right2) high = cut1-1;
            else low = cut1+1;
        }
        return 0.0;
    }
};
