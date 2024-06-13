/*
You are given an Undirected Graph having unit weight of the edges, find the shortest path from src to all the vertex and if it is unreachable to reach any vertex, 
then return -1 for that vertex.

Example 1:
Input:
n = 9, m= 10
edges=[[0,1],[0,3],[3,4],[4,5],[5,6],[1,2],[2,6],[6,7],[7,8],[6,8]] 
src=0
Output:
0 1 2 1 2 3 3 4 4

Example 2:
Input:
n = 4, m= 4
edges=[[0,0],[1,1],[1,3],[3,0]] 
src=3
Output:
1 1 -1 0

         3
       /   \  
      0     1

node 2 is not present in graph so it should be -1
*/

/*
Approach - We can use Dijsktra Algorithm for this, but we should use queue instead of priority queue because we don't shortest edge as every edge will have weight of 1 unit.
*/


vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    vector<int> adj[N];
    for(auto x:edges){
        int u = x[0];
        int v = x[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    queue<pair<int,int>> q1;
    vector<int> ans(N,INT_MAX);
    q1.push({0,src});
    ans[src] = 0;
    while(!q1.empty()){
        int node = q1.front().second;
        int dis = q1.front().first;
        q1.pop();
        for(auto x:adj[node]){
            int destNode = x;
            if(ans[destNode] > dis + 1){
                ans[destNode] = dis + 1;
                q1.push({ans[destNode],destNode});
            }
        }
        
    }
    for(int i=0;i<N;i++){
        if(ans[i] == INT_MAX){
            ans[i] = -1;
        }
    }
    return ans;
}
