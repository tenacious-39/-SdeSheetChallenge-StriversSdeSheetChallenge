/// Most optimized approach:
class Solution {
    
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){
            if(!leftRow[row] and !lowerDiagonal[row+col] and !upperDiagonal[n-1+col-row]){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[row+col] =1 ;
                upperDiagonal[n-1+col-row]=1;
                solve(col+1, n, board, ans, leftRow, lowerDiagonal, upperDiagonal);
                board[row][col] = '.';
                leftRow[row]=0;
                lowerDiagonal[row+col]=0;
                upperDiagonal[n-1+col-row]=0;
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        vector<int> leftRow(n, 0), upperDiagonal(2*n-1, 0), lowerDiagonal(2*n-1, 0);
        for(int i = 0; i<n;i++) board[i] = s;
        solve(0, n, board, ans, leftRow, lowerDiagonal, upperDiagonal);
        return ans;
    }
};

// 1st optimized approach:
class Solution {
    const bool isSafe(vector<string> &board, int row, int col, int n){
        int drow = row, dcol = col;
        
        //checking upper left diagonal:
        row--; col--;
        while(row >=0 and col >= 0){
            if(board[row][col] == 'Q') return false;
            row--; col--;
        }
        
        row = drow; col = dcol;
        
        //checking left part:
        col--;
        while(col >= 0){
            if(board[row][col] == 'Q') return false;
            col--;
        }
        
        row = drow; col = dcol;
        
        // checking lower left diagonal:
        row++; col--;
        while(row < n and col >=0){
            if(board[row][col] == 'Q') return false;
            row++; col--;
        }
        
        return true;
     }
    void solve(int col, int n, vector<string> &board, vector<vector<string>> &ans){
        if(col == n){
            ans.push_back(board);
            return;
        }
        
        for(int row = 0; row < n; row++){
            if(isSafe(board, row, col, n)){
                board[row][col] = 'Q';
                solve(col+1, n, board, ans);
                board[row][col] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for(int i = 0; i<n;i++) board[i] = s;
        solve(0, n, board, ans);
        return ans;
    }
};
