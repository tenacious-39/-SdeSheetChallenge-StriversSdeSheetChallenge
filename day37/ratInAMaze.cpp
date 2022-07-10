void solve(int row, int col, vector<vector<int>> &m, int n, string move, vector<string> &ans, vector<vector<int>> &vis){
        if(row == n-1 and col == n-1){
            ans.push_back(move);
            return;
        }
        
        //Down:
        if(row+1 < n && !vis[row+1][col] && m[row+1][col] == 1){
            vis[row][col] = 1;
            solve(row+1, col, m, n, move+'D', ans, vis);
            vis[row][col] = 0;
        }
        
        // Left:
        if(col-1 >= 0 && !vis[row][col-1] && m[row][col-1] == 1){
            vis[row][col] = 1;
            solve(row, col-1, m, n, move+'L', ans, vis);
            vis[row][col] = 0;
        }
        
        //Right:
        if(col+1 < n && !vis[row][col+1] && m[row][col+1] == 1){
            vis[row][col] = 1;
            solve(row, col+1, m, n, move+'R', ans, vis);
            vis[row][col] = 0;
        }
        
        // Up:
        if(row-1 >= 0 && !vis[row-1][col] && m[row-1][col] == 1){
            vis[row][col] = 1;
            solve(row-1, col, m, n, move+'U', ans, vis);
            vis[row][col] = 0;
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        if(m[0][0] == 1) solve(0, 0, m, n, "", ans, vis);
        return ans;
    }
