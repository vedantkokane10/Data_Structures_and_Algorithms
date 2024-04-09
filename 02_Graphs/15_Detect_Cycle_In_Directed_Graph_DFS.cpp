
/*
Approach - maitain a path array while entering the function mark it and then while exiting the loop unmark it.
in loop check if current node is visited or not, else if path for current node is marked then there is a loop.
*/


bool dfs(int node,vector<int> adj[], vector<int> &vis, vector<int> &path){
    vis[node] = 1;
    path[node] = 1;
    
    for(auto x:adj[node]){
        if(!vis[x]){
            if(dfs(x,adj,vis,path) == 1){
                return 1;
            }
        }
        else if(path[x] == 1){
            return 1;
        }
    }
    
    path[node] = 0;
    return 0;
}
bool isCyclic(int V, vector<int> adj[]) {
    vector<int> vis(V);
    vector<int> path(V);
    for(int i=0;i<V;i++){
        if(!vis[i]){
            if(dfs(i,adj,vis,path) == 1){
                return 1;
            }
        }
    }
    return 0;
}
