// Optimized approach(in place):
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        // step 1 : transpose the matrix;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(i < j) swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // step 2 : reverse every single row:
        for(int i = 0; i < n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
// Brute force Solution: (with extra 2D array)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n = matrix.size(), m = matrix[0].size();
        int ans[n][m];
         int idx = 0;
         for(int i = 0; i < m; i++){
             for(int j = n-1; j >= 0; j--){
                 ans[idx][n-1-j] = matrix[j][i];
             }
             idx++;
         }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                matrix[i][j] = ans[i][j];
            }
        }
    }
};
