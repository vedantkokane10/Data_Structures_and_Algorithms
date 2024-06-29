/*
You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). 
The nodes are numbered from 0 to n - 1 (inclusive).
You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that
there is a unidirectional edge from fromi to toi in the graph.
Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.
A node u is an ancestor of another node v if u can reach v via a set of edges.

Example 1:
Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.

Example 2:
Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.
*/


/*
Just apply Topological sort but in answer array we need to maintain vector of vector, so in topo sort inside queue first take the parent node
array and then take child node array first add all the nodes of parent in child and then insert the parent and set the update child's array.
Before returning sort each array of answer array.
*/

vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> ans(n);
    vector<int> adj[n];
    vector<int> inDegree(n,0);
    for(auto x:edges){
        int u = x[0];
        int v = x[1];
        adj[u].push_back(v);
        inDegree[v]++;
    }
    vector<int> vis(n);
    queue<int> q1;
    for(int i=0;i<n;i++){
        if(inDegree[i] == 0){
            q1.push(i);
            
        }
        cout<<i<<" "<<inDegree[i]<<endl;
        vector<int> sample;
        ans[i] = sample;
    }
    while(!q1.empty()){
        int node = q1.front();
        q1.pop();
        for(auto x:adj[node]){
            vector<int> childAncestors = ans[x];
            vector<int> nodeAncestors =  ans[node];
            set<int> s1;
            for(auto x:childAncestors){
                s1.insert(x);
            }
            for(auto x:nodeAncestors){
                if(s1.find(x) == s1.end()){
                    childAncestors.push_back(x);
                }
            }
            childAncestors.push_back(node);
            ans[x] = childAncestors;
            inDegree[x]--;
            if(inDegree[x] == 0){
                q1.push(x);
            }
        }
    }
    for(int i=0;i<n;i++){
        vector<int> arr = ans[i];
        sort(arr.begin(),arr.end());
        ans[i] = arr;
    }
    return ans;
}
