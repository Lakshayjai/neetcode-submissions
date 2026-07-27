class Solution {
public:
    void dfs(int n, int m, vector<vector<int>>& grid, int x, int y, vector<vector<int>>& visited, int& cnt){
        visited[x][y] = 1;
        cnt++;

        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        for(int i = 0; i < 4; i++){
            int newx = x + dx[i];
            int newy = y + dy[i];

            if(newx >= 0 and newy >= 0 and newx < n and newy < m 
                and grid[newx][newy] == 1 and visited[newx][newy] != 1){
                    dfs(n, m, grid, newx, newy, visited, cnt);
                }
        }
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxCnt = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1 and visited[i][j] != 1){
                    int cnt = 0;
                    dfs(n, m, grid, i, j, visited, cnt);
                    maxCnt = max(cnt, maxCnt);
                }
            }
        }

        return maxCnt;
    }
};
