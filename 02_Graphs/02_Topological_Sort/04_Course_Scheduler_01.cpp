/*
There are a total of N tasks, labeled from 0 to N-1. Some tasks may have prerequisites, for example to do task 0 you have to first complete task 1, which is expressed as a pair: [0, 1]
Given the total number of tasks N and a list of prerequisite pairs P, find if it is possible to finish all tasks.

Input: 
N = 4, P = 3
prerequisites = {{1,0},{2,1},{3,2}}
Output:
Yes
Explanation:
To do task 1 you should have completed
task 0, and to do task 2 you should 
have finished task 1, and to do task 3 you 
should have finished task 2. So it is possible.
*/


/*
Approach - Apply toposort and check if every node covered i.e if any node is not covered that means it is not possible.
*/

bool isPossible(int V,int P, vector<pair<int, int> >& prerequisites) {
    // Code here
    vector<int> adj[V];
    for(auto x:prerequisites){
        int destination = x.first;
        int source = x.second;
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
          return 1;
      }
      return 0;
    
}
