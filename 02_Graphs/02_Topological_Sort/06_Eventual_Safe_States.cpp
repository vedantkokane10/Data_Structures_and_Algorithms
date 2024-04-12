/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.
A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.
You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

*/

/*
Approach - Apply toposort and then just sort the answer array and return it.
*/
vector<int> bfs(int V, vector<int> adj[]){
    vector<int> ans;
    queue<int> q1;
    vector<int> inDegree(V);
    for(int i=0;i<V;i++){
        for(auto x:adj[i]){
            inDegree[x]++;
        }
    }
    for(int i=0;i<V;i++){
        if(inDegree[i] == 0){
            q1.push(i);
        }
    }
    while(!q1.empty()){
        int node = q1.front();
        q1.pop();
        ans.push_back(node);
        for(auto x:adj[node]){
            inDegree[x]--;
            if(inDegree[x] == 0){
                q1.push(x);
            }
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}
vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
    // code here
    vector<int> adjRev[V]; // reverse adj list
    
    for(int i=0;i<V;i++){
        // edge is from i -> to x
        for(auto x:adj[i]){
            // so we need to make edge from  x -> i
            // this means it will. be reversed
            adjRev[x].push_back(i);
        }
    }
    return bfs(V,adjRev);
}
