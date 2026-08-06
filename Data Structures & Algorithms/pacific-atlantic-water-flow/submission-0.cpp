class Solution {
public:
    vector<vector<int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void DFS(vector<vector<int>>& heights, int i, int j, int preVal, vector<vector<bool>>& visited, int m, int n){
        if(i < 0 or j < 0 or i >= m or j >= n) return;
        if(visited[i][j]) return;
        if(heights[i][j] < preVal) return;

        visited[i][j] = true;

        for(auto dir : directions){
            int newi = i + dir[0];
            int newj = j + dir[1];

            DFS(heights, newi, newj, heights[i][j], visited, m, n);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> ans;

        vector<vector<bool>> pacificVisited(m, vector<bool>(n, false));
        vector<vector<bool>> atlanticVisited(m, vector<bool>(n, false));


        // Top and Bottom row, Top for pacific and Bottom for atlantic
        for(int j = 0; j < n; j++){
            DFS(heights, 0, j, INT_MIN, pacificVisited, m, n);
            DFS(heights, m-1, j, INT_MIN, atlanticVisited, m, n);
        }

        // left and right col, left for pacific and right for atlantic
        for(int i = 0; i < m; i++){
            DFS(heights, i, 0, INT_MIN, pacificVisited, m, n);
            DFS(heights, i, n-1, INT_MIN, atlanticVisited, m, n);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(pacificVisited[i][j] and atlanticVisited[i][j]) ans.push_back({i, j});
            }
        }
        
        return ans;
    }
};
