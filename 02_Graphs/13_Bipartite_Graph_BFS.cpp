// Bipartite Graph - It is a graph in which no adjancent nodes can be colored with the same color.

/*
Ex    
       0 - 1 
     /       \
0 - 1         0 - 1
     \       /
       0 - 1

Approach - We will use BFS.
Instead of using visited array logic we will use a color array which will be set to -1 initially.
Then we can send nodes to bfs function (Assuming components)
and set the color of the current first source node to 0.
Then by applying bfs logic we can get front node and its color and then by iterating through its adjacent nodes
I will check if any node has the same color as the current node if yes then Graph is not bipartite else set the color to negation of current node's color.
*/

bool bfs(int node,vector<int>adj[],vector<int> &color){
      queue<int> q1;
      color[node] = 0;
      q1.push(node);
      while(!q1.empty()){
          int node = q1.front();
          int currentColor = color[node];
          q1.pop();
          for(auto x:adj[node]){
              if(color[x] == -1){
                  color[x] = !(currentColor);
                  q1.push(x);
              }
              else if(color[x] == currentColor){
                  return 0;
              }
          }
      }
      return 1;
  }
  
  
bool isBipartite(int V, vector<int>adj[]){
    vector<int> color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i] == -1){
            if(bfs(i,adj,color) == 0){
                return 0;
            }
        }
    }
    return 1;
}
