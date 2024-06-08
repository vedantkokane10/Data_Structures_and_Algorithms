/* 417. Pacific Atlantic Water Flow
There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. 
Water can flow from any cell adjacent to an ocean into the ocean.
Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.
Input: 
heights = 
              [
                    PACIFIC
               |  [1,2,2,3,5],  |
               |  [3,2,3,4,4],  | 
PACIFIC  -->   |  [2,4,5,3,1],  |       --> ATLANTIC
               |  [6,7,1,4,5],  |
               |  [5,1,1,2,4]   | 
                    ATLANTIC
              }
                  
Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
Explanation: The following cells can flow to the Pacific and Atlantic oceans, as shown below:
[0,4]: [0,4] -> Pacific Ocean 
       [0,4] -> Atlantic Ocean
[1,3]: [1,3] -> [0,3] -> Pacific Ocean 
       [1,3] -> [1,4] -> Atlantic Ocean
[1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean 
       [1,4] -> Atlantic Ocean
[2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean 
       [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
[3,0]: [3,0] -> Pacific Ocean 
       [3,0] -> [4,0] -> Atlantic Ocean
[3,1]: [3,1] -> [3,0] -> Pacific Ocean 
       [3,1] -> [4,1] -> Atlantic Ocean
[4,0]: [4,0] -> Pacific Ocean 
       [4,0] -> Atlantic Ocean
Note that there are other possible paths for these cells to flow to the Pacific and Atlantic oceans.
*/


/*
Approach -
Observation --> 1) if a cell meets top row or left column then it meets pacific ocean.
                2) if a cell meets bottom row or right column then it meets altantic ocean.

So, we need to pass top row and  bottom row cells and check using bfs for adjacent cells which are >= to current cells. (Initiallly the cells will be top and bottom row
so the adjacent cells must have value more than or equal to initial cells.
In question it is given move to adjacent cells which are less or equal to current cell values,
but since we are passing corner row and columns we need to check for more than or equal to.

Then after that we need to pass left row and right column cells and check using bfs for adjacent cells which are >= to current cells.

After all this we will run loop (nxm) and check for individual cells whether they are visited or not by both oceans visited arrays if they are then they 
are one of our answer. So put that cell indexes in answer array.
At end return answer array
*/

bool bfs(int row,int col,vector<vector<int>>& heights,vector<vector<bool>>& vis){
    int m = heights.size();
    int n = heights[0].size();
    vis[row][col] = 1;
    queue<pair<int,int>> q1;
    q1.push({row,col});
    while(!q1.empty()){
        int row = q1.front().first;
        int col = q1.front().second;
        q1.pop();
        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow  >= 0 && nrow < m && ncol >= 0 && ncol < n){
                if(!vis[nrow][ncol]){
                    if(heights[nrow][ncol] >= heights[row][col]){
                        q1.push({nrow,ncol});
                        vis[nrow][ncol] = 1;
                    }
                }
            }
        }
    }
    return 0;
}


vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<int>> ans;
    vector<vector<bool>> pacific(m,vector<bool>(n,0));
    vector<vector<bool>> altantic(m,vector<bool>(n,0));

    // top and bottom rows
    for(int i=0;i<n;i++){
        // pacific -> top row
        bfs(0,i,heights,pacific);
        // atlantic -> bottom row
        bfs(m-1,i,heights,altantic);
    }
    // left and right rows
    for(int i=0;i<m;i++){
        // pacific -> left row
        bfs(i,0,heights,pacific);
        // atlantic -> right row
        bfs(i,n-1,heights,altantic);
    }

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(pacific[i][j] && altantic[i][j]){
                ans.push_back({i,j});
            }                
        }
    }
    return ans;
}
