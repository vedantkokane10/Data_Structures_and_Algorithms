/*
You are a hiker preparing for an upcoming hike. You are given heights,
a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col).
You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). 
You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].
*/


// Applied Dijkstra Algorithm for matrix
// kept node -> {distance,{row,col}}
// distance - absolute difference between cell values

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size();
    int n = heights[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q1;
    int dr[4] = {0,-1,0,1};
    int dc[4] = {-1,0,1,0};
    vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
    q1.push({0,{0,0}});
    dis[0][0] = 0;
    int ans = INT_MIN;
    while(!q1.empty()){
        int distance = q1.top().first;
        int row = q1.top().second.first;
        int col = q1.top().second.second;
        ans = max(ans,distance);
        q1.pop();
        if(row == m-1 && col == n-1){
            break;
        }
        for(int i=0;i<4;i++){
            int nrow = row + dr[i];
            int ncol = col + dc[i];
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n){
                int currDistance = abs(heights[row][col] - heights[nrow][ncol]);
                if(currDistance < dis[nrow][ncol]){
                    dis[nrow][ncol] = currDistance;
                    q1.push({currDistance,{nrow,ncol}});
                }
            }
        }
    }
    return ans;
}
