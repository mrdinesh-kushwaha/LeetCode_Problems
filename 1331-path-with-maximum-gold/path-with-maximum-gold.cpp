class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>& grid, int i, int j) {
    // Boundary conditions
    int row = grid.size();
    int col = grid[0].size();
    if (i >= row || i < 0 || j >= col || j < 0 || grid[i][j] == 0) {
        return 0;
    }
    int maxGold = 0;
    int temp = grid[i][j];
    //sum += temp;

    // Mark current cell as visited
    grid[i][j] = 0;

    for(vector<int>&dir:directions){
        int new_i= i+dir[0];
        int new_j= j+ dir[1];

        maxGold=max(maxGold,dfs(grid,new_i ,new_j));
    }
    // Explore adjacent cells
    // int up = dfs(grid, i - 1, j);
    // int down = dfs(grid, i + 1, j);
    // int left = dfs(grid, i, j - 1);
    // int right = dfs(grid, i, j + 1);

    // Restore current cell
    grid[i][j] = temp;

    // Calculate maxGold from all possible paths
   // maxGold = max({ maxGold, up, down, left, right }) + temp;

    return maxGold+temp;
}

int getMaximumGold(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    int maxGold = 0;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (grid[i][j] != 0) {
                maxGold = max(maxGold, dfs(grid, i, j));
            }
        }
    }

    return maxGold;

    }
};