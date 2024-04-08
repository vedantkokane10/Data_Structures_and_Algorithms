/*
Given an m x n matrix board containing 'X' and 'O', capture all regions that are 4-directionally surrounded by 'X'.
A region is captured by flipping all 'O's into 'X's in that surrounded region.
Input: 
board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: Notice that an 'O' should not be flipped if:
- It is on the border, or
- It is adjacent to an 'O' that should not be flipped.
The bottom 'O' is on the border, so it is not flipped.
The other three 'O' form a surrounded region, so they are flipped.

Example 2:
Input: board = [["X"]]
Output: [["X"]]
*/

/*
Approach - 
Iterate over the border rows and columns of the matrix and mark the cells which are not visited and have value 'O' then apply to BFS to that cell 
by covering all its adjacent neighbours (up,down,left,right). Once all the cells which have value 'O' or have been connected to cells who have value 'O' are marked
we can manually iterate over the matrix and mark cells with value 'O' to 'X' which are not visited.
*/


void bfs(int row,int col,vector<vector<char>>& board ,vector<vector<bool>>& vis){
    int n = board.size(), m = board[0].size();
    vis[row][col] = 1;
    queue<pair<int,int>> q1;
    q1.push({row,col});
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    while(!q1.empty()){
        int row = q1.front().first;
        int col = q1.front().second;
        q1.pop();
        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                if(!vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                    vis[nrow][ncol] = 1;
                    q1.push({nrow,ncol});
                }
            }
        }
    }
}
void solve(vector<vector<char>>& board) {
    int n = board.size(), m = board[0].size();
    vector<vector<bool>> vis(n,vector<bool>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 || j == 0 || i == n-1 || j == m-1){
                if(!vis[i][j] && board[i][j] == 'O'){
                    bfs(i,j,board,vis);
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && board[i][j] == 'O'){
                board[i][j] = 'X';
            }
            
        }
    }
    
}
