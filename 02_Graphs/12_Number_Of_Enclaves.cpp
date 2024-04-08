/*
Approach - We will use bfs or we can also use dfs.
We will first push all the border 1s and then we will use bfs to make sure all the adjacent 1s 
to the border 1s are visited and also the original has it marked as 0.
Then just iterate over the grid and find no of 1s and return the answer.
*/

int numberOfEnclaves(vector<vector<int>> &grid) {
    int cnt = 0;
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    queue<pair<int,int>> q1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1){
                if(!vis[i][j] && grid[i][j] == 1){
                    vis[i][j] = 1;
                    q1.push({i,j});
                }
            }
        }
    }
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    while(!q1.empty()){
        int row = q1.front().first;
        int col = q1.front().second;
        grid[row][col] = 0;
        q1.pop();
        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                if(!vis[nrow][ncol] && grid[nrow][ncol] == 1){
                    vis[row][ncol] = 1;
                    q1.push({nrow,ncol});
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                cnt++;
            }
        }
    }
    
    return cnt;
}
