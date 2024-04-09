/*
Approach - Find Topological sort by either of BFS/DFS and then just compare if 
the all the nodes covered or not. If all nodes are not covered then there is cycle.
*/


bool isCyclic(int V, vector<int> adj[]) {
    vector<int> inDegree(V,0);
    for(int i=0;i<V;i++){
        for(auto x:adj[i]){
            inDegree[x]++;
        }
    }
    queue<int> q1;
    for(int i=0;i<V;i++){
        if(inDegree[i] == 0){
            q1.push(i);
        }
    }
    int cnt = 0;
    while(!q1.empty()){
        int node = q1.front();
        cnt++;
        q1.pop();
        for(auto x:adj[node]){
            inDegree[x]--;
            if(inDegree[x] == 0){
                q1.push(x);
            }
        }
    }
    
    if(cnt == V){
        return 0;
    }
    
    return 1;
}
