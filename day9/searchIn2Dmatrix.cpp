// best for leetcode >>>> O(log(N*M))
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = (n*m)-1;
        while(low <= high){
            int mid = (low+high)/2;
            int row = mid/m, col = mid%m;
            if(matrix[row][col] == target) return true;
            else if(matrix[row][col] < target) low = mid+1;
            else high = mid-1;
         } return false;
    }
};


// better for LC and optimal for GFG
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int i = 0, j = m-1;
        while(i < n and j >= 0){
            if(target == matrix[i][j]) return true;
            if(matrix[i][j] > target) j--;
            else i++;
        }return false;
    }
};
