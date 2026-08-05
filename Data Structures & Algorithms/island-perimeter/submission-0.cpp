class Solution {
public:
    int cnt = 0;

    void dfs(int x, int y, vector<vector<int>>&grid, vector<vector<bool>>&visited, int n, int m){


        if(x < 0 or y < 0 or x >= n or y >= m or grid[x][y] == 0){
            cnt++;
            return;
        }

        if(visited[x][y]) return;

        visited[x][y] = true;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {-1, 1, 0, 0};
        
        for(int i = 0; i < 4; i++){
            dfs(x+dx[i], y+dy[i], grid, visited, n, m);
        }
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 and !visited[i][j]){
                    dfs(i, j, grid, visited, n, m);
                }
            }
        }
        return cnt;
    }
};