/*
We need to print entire path (from 1 to n)
You are given a weighted undirected graph having n vertices numbered from 1 to n and m edges describing there are edges between a to b with some weight, 
find the shortest path between the vertex 1 and the vertex n and if path does not exist then return a list consisting of only -1.
Note - 
1. If there exists a path, then return a list whose first element is the weight of the path.
2. If no path exists then return a list containing a single element -1.

Example:
Input:
n = 5, m= 6
edges = [[1,2,2], [2,5,5], [2,3,4], [1,4,1],[4,3,3],[3,5,1]]
Output:
5 1 4 3 5
Explaination:
Shortest path from 1 to n is by the path 1 4 3 5 whose weight is 5. 
*/

/*
Approach - Use Dijkstra algo but along with it always store the parent node if a shorter distance from one to another is found.
Initialize parent array with index of each element i,e 1 to n.
Then at last iterate from nth node until parent is equal to iteself and add 1 and distance[n] and return the answer array.

*/

vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
    // Code here
    vector<pair<int,int>> adj[n+1];
    for(auto x:edges){
        int u = x[0];
        int v = x[1];
        int weight = x[2];
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
    }
    vector <int> distance(n+1,INT_MAX);
    vector <int> parent(n+1,0);
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    distance[1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q1;
    q1.push({0,1});
    while(!q1.empty()){
        int node = q1.top().second;
        int dist = q1.top().first;
        q1.pop();
        for(auto& x : adj[node]){
            int adjNode = x.first;
            int adjDist = x.second;
            if(dist + adjDist < distance[adjNode]){
                distance[adjNode] = dist + adjDist;
                q1.push({distance[adjNode], adjNode});
                parent[adjNode] = node;
            }
        }
    }
    
    if(distance[n] == INT_MAX){
        return {-1};
    }
    
    int node = n;
    vector<int> ans;
    while(parent[node] != node){
        ans.push_back(node);
        node = parent[node];
    }
    ans.push_back(1);
    ans.push_back(distance[n]);
    reverse(ans.begin(),ans.end());
    return ans;
}
