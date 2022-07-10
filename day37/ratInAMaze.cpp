//---------------------------------------------------------------------------------------------------------------------------------------------
//        ##More clean Code

void solve(int row, int col, vector<vector<int>> &m, int n, string move, vector<string> &ans, vector<vector<int>> &vis, int di[], int dj[]){
        if(row == n-1 and col == n-1){
            ans.push_back(move);
            return;
        }
        string s = "DLRU";
        for(int i = 0; i < 4; i++){
            if(row+di[i] >= 0 and row+di[i] < n and col+dj[i] >= 0 and col+dj[i] < n and !vis[row+di[i]][col+dj[i]] and m[row+di[i]][col+dj[i]] == 1){
                vis[row][col] = 1;
                solve(row+di[i], col+dj[i], m, n, move+s[i], ans, vis, di, dj);
                vis[row][col] = 0;
            }
        }
    }
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int di[] = {1, 0, 0, -1};
        int dj[] = {0, -1, 1, 0};
        if(m[0][0] == 1) solve(0, 0, m, n, "", ans, vis, di, dj);
        return ans;
    }

//-------------------------------------------------------------------------------------------------------------------------------
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
