class Solution {
public:

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            
            q.pop();

            for(auto [dr, dc] : dir){
                int nr = dr + r;
                int nc = dc + c;

                if(nr < 0 or nc < 0 or nr >= m or nc >= n) continue;

                if(grid[nr][nc] != INT_MAX) continue;
            
                grid[nr][nc] = 1 + grid[r][c];

                q.push({nr, nc});
            }
        }
    }
};
