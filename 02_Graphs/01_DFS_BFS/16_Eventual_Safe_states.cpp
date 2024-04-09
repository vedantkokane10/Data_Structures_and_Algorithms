/*
Question :
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.
*/
/*
Approach - Same approach as detecting cycle in directed graph but we have a new array of safe to find whether a node is safe or not.
So while entering in the dfs function we set safe[currentNode] = 0 then while exiting if no cycle is there so we change the
safe[currentNode] = 1.
*/


bool dfs(int node,vector<int> adj[],vector<bool> &vis,vector<bool> &path,vector<bool> &safe){
  vis[node] = 1;
  path[node] = 1;
  safe[node] = 0;
  for(auto x:adj[node]){
      if(!vis[x]){
          if(dfs(x,adj,vis,path,safe) == 1){
              return 1;
          }
      }
      else if(path[x] == 1){
          return 1;
      }
  }
  
  safe[node] = 1;
  path[node] = 0;
  return 0;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
   vector<bool> safe(V);
   vector<bool> vis(V);
   vector<bool> path(V);
   vector<int> ans;
   for(int i=0;i<V;i++){
       if(!vis[i]){
           dfs(i,adj,vis,path,safe);
       }
   }
   for(int i=0;i<V;i++){
       if(safe[i]){
           ans.push_back(i);
       }
   }
   return ans;
}
