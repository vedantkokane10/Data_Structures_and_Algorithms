/*
For Topological sort the graph should be Directed Acyclic Graph (DAG).
In Topological sort - a order is maintained.
A nodes occurs only if its predecessor has already occured.
ex -> 1 -> 2 -> 3
1 2 3 ==> 3 will occur if 2 has occured, 2 will occur if 1 has occured
*/

/*
Approach - use traditional dfs just maintain a stack and during the exit from the function
push the node in the stack. Then iterate over the elements of stack and return the array of nodes.
*/

void dfs(int node,vector<int> adj[],vector<bool> &vis,stack<int> &s1){
    vis[node] = 1;
    for(auto x: adj[node]){
        if(!vis[x]){
            dfs(x,adj,vis,s1);
        }
    }
    s1.push(node);
}
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<bool> vis(V,0);
    stack<int> s1;
    for(int i=0;i<V;i++){
        if(!vis[i]){
            dfs(i,adj,vis,s1);
        }
    }
    vector<int> ans;
    while(!s1.empty()){
        int x = s1.top();
        ans.push_back(x);
        s1.pop();
    }
    return ans;
}
