/*
You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Ex - Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Ex - Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
*/

int orangesRotting(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    queue<pair<pair<int,int>,int>> q1;
    vector<vector<bool>> vis(m,vector<bool>(n,0));
    int noOfOnes = 0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 2){
                q1.push({{i,j},0});
                vis[i][j] = 1;
            }
            if(grid[i][j] == 1){
                noOfOnes++;
            }
        }
    }
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    int time = 0;
    int ones = 0;
    while(!q1.empty()){
        int row = q1.front().first.first;
        int col = q1.front().first.second;
        int currentTime = q1.front().second;
        q1.pop();
        time = max(time,currentTime);
        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                if(!vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    ones++;
                    q1.push({{nrow,ncol},currentTime+1});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }

    if(noOfOnes != ones){
        return -1;
    }
    return time;

}
