// Also know as Kahn Algorithm
/*
First Calculate the in degree for each node. Intially put all node in queue which have 0 in degree.
Then pop front nodes and remove the edges from current node to the destination node. If the in degree
of destination node is 0 then push that node in queue.
Push front nodes in answer array.
*/

vector<int> topoSort(int V, vector<int> adj[]) 
{
    vector<int> ans;
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
    while(!q1.empty()){
        int node = q1.front();
        ans.push_back(node);
        q1.pop();
        for(auto x:adj[node]){
            inDegree[x]--;
            if(inDegree[x] == 0){
                q1.push(x);
            }
        }
    }
    return ans;
}
