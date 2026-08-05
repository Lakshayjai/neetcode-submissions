class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int time = 0;
        int fresh = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if (fresh == 0) return 0;
        
        int dx[] = {0, 0, 1, -1};
        int dy[] = {1, -1, 0, 0};

        while(!q.empty()){
            
            int len = q.size();
            bool isRotten = false;
    
            for(int i = 0; i < len; i++){
                auto curr = q.front();
                q.pop();
                int r = curr.first;
                int c = curr.second;

                for(int j = 0; j < 4; j++){
                    int row = r + dx[j];
                    int col = c + dy[j];

                    if(row >= 0 and col >= 0 and row < n and col < m and grid[row][col] == 1){
                        grid[row][col] = 2;
                        q.push({row, col});
                        fresh--;
                        isRotten = true;
                    }
                }
            }
            if(isRotten) time++;
        }
        if(fresh == 0) return time;
        return -1;
    }
};
