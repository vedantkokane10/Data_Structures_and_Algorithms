/*
Given a weighted, undirected, and connected graph with V vertices and E edges, your task is to find the sum of the weights of the edges in the Minimum Spanning Tree (MST) of the graph. 
The graph is represented by an adjacency list, where each element adj[i] is a vector containing vector of integers. 
Each vector represents an edge, with the first integer denoting the endpoint of the edge and the second integer denoting the weight of the edge.

Input:
3 3
0 1 5
1 2 3
0 2 1

      0
  5 /    \ 1
  /       \  
1 -------- 2
      3

MST - 
      0
         \ 1
          \  
1 -------- 2
      3
Weight of MST - 4
    
*/

/*
Approach - Have priority Queue (minimum edge on top) of weight and source data type and then iterate over while the queue is not empty 
pop the top edge and check if source is visited or not if not visited then mark it as visited and also visit each edge from source and
add the edge to the queue if the destination node of edge is not visited. 
*/


int spanningTree(int V, vector<vector<int>> adj[])
{
   // prim Algorithm 
   int sum = 0;
   priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q1;
   q1.push({0,0});
   vector<int> vis(V);
   while(!q1.empty()){
       int weight = q1.top().first;
       int source = q1.top().second;
       q1.pop();
       if(vis[source] == 1){
           continue;
       }
       else{
           sum += weight;
           vis[source] = 1;
           for(auto x: adj[source]){
               int edgeWeight = x[1];
               int destination = x[0];
               if(!vis[destination]){
                   q1.push({edgeWeight,destination});
               }
           }
       }
       
   }
   
   return sum;
}
