/*
Approach - 
Keep track of parent along with the current node
if a node is already visited and if it is not the parent node then there is a cycle.

Logic - whenever we iterate in a graph before visiting a node, we first visit its parent, So its fine if
the parent is already visited, but if a node which is not the parent of the current node and if it is still 
visited then that means there is a cycle.
*/

bool dfs(int node,int parent,vector<int> adj[],vector<bool> &vis){
    vis[node] = 1;
    vis[parent] = 1;
    for(auto x:adj[node]){
        if(x != parent){
            if(!vis[x]){
                if(dfs(x,node,adj,vis) == 1){
                    return 1;
                }
            }
            else{
                return 1;
            }
        }
    }
    return 0;
}

bool isCycle(int V, vector<int> adj[]) {
    // Code here
    vector<bool> vis(V,0);
    // We are checking for each node becasue there can non-connected graph components present
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,i,adj,vis) == 1){
                return 1;
            }
        }
    }
    return 0;
}
