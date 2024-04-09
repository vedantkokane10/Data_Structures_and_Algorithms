// Bipartite Graph - It is a graph in which no adjancent nodes can be colored with the same color.

/*
Ex    
       0 - 1 
     /       \
0 - 1         0 - 1
     \       /
       0 - 1

Approach - We will use DFS.
In function we will maintain a extra argument called currentColor and everytime while passing the sourceNode we will pass 0 as currentColor.
Then inside the function first we will set color of current node to the currentColor and then iterate and if color of iterated node is -1
then check for dfs and pass negation of currentColor !currentColor.
else if color of iterated node is equal to currentColor then return 0
*/


bool dfs(int node,int currentColor,vector<int>adj[],vector<int> &color){
      color[node] = currentColor;
      for(auto x:adj[node]){
          if(color[x] == -1){
              if(dfs(x,!currentColor,adj,color) == 0){
                  return 0;
              }
          }
          else if(color[x] == currentColor){
              return 0;
          }
      }
      return 1;
  }
  
bool isBipartite(int V, vector<int>adj[]){
    vector<int> color(V,-1);
    for(int i=0;i<V;i++){
        if(color[i] == -1){
            if(dfs(i,0,adj,color) == 0){
                return 0;
            }
        }
    }
    return 1;
}
