class Solution {
public:
    void doBfs(int i, int j, vector<vector<char>> &grid, int dx[], int dy[]){
        queue<pair<int,int>> q;
        q.push({i, j});
        while(!q.empty()){
            pair<int, int> idx = q.front();
            q.pop();
            for(int ind = 0; ind < 4; ind++){
                int nx = idx.first+dx[ind], ny = idx.second+dy[ind];
                if(nx < 0 or ny < 0 or nx >= grid.size() or ny >= grid[0].size() or grid[nx][ny] == '0') continue;
                grid[nx][ny] = '0';
                q.push({nx, ny});
                //cout << "nx = " << nx << " ny = " << ny << "\n";
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};
        for(int i = 0; i < n; i++){
            for(int j =0; j<m; j++){
                if(grid[i][j] == '1'){
                    cnt++;
                    grid[i][j] = '0';
                    doBfs(i, j, grid, dx, dy);
                    //cout << "i = " << i << "j = " << j << "\n";
                }
            }
        }
        
        return cnt;
    }
};
