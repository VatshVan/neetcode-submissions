class Solution {
private:
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void dfs(vector<vector<int>>& grid, int r, int c, int& area) {
        if (r < 0 || c < 0 || r >= grid.size() ||
            c >= grid[0].size() || grid[r][c] == 0)
            return;
        grid[r][c] = 0;
        area++;
        for (int i = 0; i < 4; i++) {
            dfs(grid, r + directions[i][0], c + directions[i][1], area);
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ROWS = grid.size(), COLS = grid[0].size(), maxArea = 0;
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 1) {
                    int area = 0;
                    dfs(grid, r, c, area);
                    maxArea = max(maxArea, area);
                }
            }
        }
        return maxArea;
    }
};