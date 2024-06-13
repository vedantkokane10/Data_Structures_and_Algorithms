/*
Given a Directed Acyclic Graph of N vertices from 0 to N-1 and a 2D Integer array(or vector) edges[ ][ ] of length M,
where there is a directed edge from edge[i][0] to edge[i][1] with a distance of edge[i][2] for all i.
Find the shortest path from src(0) vertex to all the vertices and if it is impossible to reach any vertex, then return -1 for that vertex.

Example1:
Input:
N = 4, M = 2
edge = [[0,1,2],[0,2,1]]
Output:
0 2 1 -1
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->2 with edge weight 1.
There is no way we can reach 3, so it's -1 for 3.

Example2:
Input:
N = 6, M = 7
edge = [[0,1,2],[0,4,1],[4,5,4],[4,2,2],[1,2,3],[2,3,6],[5,3,1]]
Output:
0 2 3 6 1 5
Explanation:
Shortest path from 0 to 1 is 0->1 with edge weight 2. 
Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3.
Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6.
Shortest path from 0 to 4 is 0->4 with edge weight 1.
Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.
*/

/*
Approach - Apply traditional Dijkstra Algo but instead of unit weight consider the edge weight, as graph directed and acyclic.
*/

vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
    vector<vector<int>> adj[N];
    for(auto x:edges){
        int u = x[0];
        int v = x[1];
        int weight = x[2];
        adj[u].push_back({v,weight});
    }
    queue<pair<int,int>> q1;
    vector<int> ans(N,INT_MAX);
    ans[0] = 0;
    q1.push({0,0});
    while(!q1.empty()){
        int node = q1.front().second;
        int dis = q1.front().first;
        q1.pop();
        for(auto x:adj[node]){
            int destNode = x[0];
            int weight = x[1];
            if(ans[destNode] > dis + weight){
                ans[destNode] = dis + weight;
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
