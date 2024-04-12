/*
There are a total of n tasks you have to pick, labelled from 0 to n-1. Some tasks may have prerequisite tasks,
for example to pick task 0 you have to first finish tasks 1, which is expressed as a pair: [0, 1]
Given the total number of n tasks and a list of prerequisite pairs of size m. Find a ordering of tasks you should pick to finish all tasks.
Note: There may be multiple correct orders, you just need to return any one of them. If it is impossible to finish all tasks, return an empty array. 
Driver code will print "No Ordering Possible", on returning an empty array. Returning any correct order will give the output as 1, whereas any invalid order will give the output 0. 

Input:
n = 2, m = 1
prerequisites = {{1, 0}}
Output:
1
Explanation:
The output 1 denotes that the order is valid. So, if you have, implemented your function correctly, then output would be 1 for all test cases. One possible order is [0, 1].
*/


/*
Approach - Apply Toposort and store the answer in ans array if size of the array is not equal to no of nodes then return empty array else return array. 
*/

vector<int> findOrder(int V, int m, vector<vector<int>> prerequisites) 
{
  vector<int> adj[V];
  for(auto x:prerequisites){
      int destination = x[0];
      int source = x[1];
      adj[source].push_back(destination);
  }
  
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
    vector<int> ans;
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
    if(ans.size() != V){
        return {};
    }
    return ans;
}
