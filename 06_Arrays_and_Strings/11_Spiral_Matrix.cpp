/*
You start at the cell (rStart, cStart) of an rows x cols grid facing east. 
The northwest corner is at the first row and column in the grid, and the southeast corner is at the last row and column.
You will walk in a clockwise spiral shape to visit every position in this grid. 
Whenever you move outside the grid's boundary, we continue our walk outside the grid (but may return to the grid boundary later.). 
Eventually, we reach all rows * cols spaces of the grid.
Return an array of coordinates representing the positions of the grid in the order you visited them.

Input: rows = 1, cols = 4, rStart = 0, cStart = 0
Output: [[0,0],[0,1],[0,2],[0,3]]
 
*/
/*
Observe pattern we can find

No of times => Step 

1 time    2 times
Step-1    Step-2
R1        R3
D1        D3
L2        L4
U2        U4



*/

vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    //           R D L  U
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};

    vector<vector<int>> ans;

    int r = rStart;
    int c = cStart;
    
    int steps = 1;
    int i = 0;

    while(ans.size() < (rows * cols)){
        // 1 Right , 1 Down and similarly 1 left , 1 Up, So 2 
        for(int j=0;j<2;j++){
            int drow = dr[i];
            int dcol = dc[i];
            for(int s=0;s<steps;s++){
                if(r >= 0 && r < rows && c >= 0 && c < cols){
                    ans.push_back({r,c});
                }
                r = r + drow;
                c = c + dcol;
            }
            // incremeting i for directions  R -> D -> L -> U
            i = (i+1) % 4;
        }
        // incrementing steps no of times to move in a particular direction
        steps ++;
    }

    return ans;
}
