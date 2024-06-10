/*
Given a weighted, undirected and connected graph of V vertices and an adjacency list adj where adj[i] is a list of lists containing 
two integers where the first integer of each list j denotes there is edge between i and j ,
second integers corresponds to the weight of that  edge . 
You are given the source vertex S and You to Find the shortest distance of all the vertex's from the source vertex S.
You have to return a list of integers denoting shortest distance between each node and Source vertex S.

Note: The Graph doesn't contain any negative weight cycle.

Input:
V = 2

    0
   /
9 /
 /
1
adj [] = {{{1, 9}}, {{0, 9}}}
S = 0
Output:
0 9

V = 3, E = 3
adj = {{{1, 1}, {2, 6}}, {{2, 3}, {0, 1}}, {{1, 3}, {0, 6}}}
S = 2
Output:
4 3 0
For nodes 2 to 0, we can follow the path-
2-1-0. This has a distance of 1+3 = 4,
whereas the path 2-0 has a distance of 6. So,
the Shortest path from 2 to 0 is 4.
The shortest distance from 0 to 1 is 1 .


Dijkstra doesn't work on any negative weighted cycle.
*/


vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    vector <int> dis(V,INT_MAX);
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> q1;
    dis[S] = 0;
    // pair -> (first = Distance , second = Node)
    // First Distance is considered because we want the shortest edge at top of priority_queue
    q1.push({0,S});
    while(!q1.empty()){
        int distance = q1.top().first;
        int node = q1.top().second;
        q1.pop();
        for(auto x:adj[node]){
            int adjNode = x[0];
            int adjDistance = x[1];
            if(adjDistance + distance < dis[adjNode]){
                dis[adjNode] = adjDistance + distance;
                q1.push({dis[adjNode], adjNode});
            }
        }
    }
    return dis;
}
