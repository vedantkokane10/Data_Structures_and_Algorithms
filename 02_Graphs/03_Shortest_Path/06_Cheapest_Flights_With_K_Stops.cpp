/*
There are n cities connected by some number of flights. 
You are given an array flights where flights[i] = [fromi, toi, pricei] indicates
that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k,
return the cheapest price from src to dst with at most k stops. 
If there is no such route, return -1.

Ex 1
         0
       /  \
100   /    \  100
     1      2 
60    \     /  200
       \  /
        3

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.


Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 2 is marked in red and has cost 100 + 100 = 200.
*/

/*
node -> {Stops , price , node}
Source and destination are not counted in k stops, so k won't be affected.
approach - apply dijsktra while checking check if it is destination node or not if destination do dont care for stops else care for stops and 
update it.
*/

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<pair<int,int>> adj[n];
    for(auto x:flights){
        int source = x[0];
        int dest = x[1];
        int price = x[2];
        adj[source].push_back({dest,price});
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q1;
    q1.push({0,{0,src}});
    vector<int> priceToReach(n,INT_MAX);
    while(!q1.empty()){
        int stops = q1.top().first;
        int price = q1.top().second.first;
        int node = q1.top().second.second;
        q1.pop();
    
        for(auto x:adj[node]){
            int newPrice = price + x.second;
            if(stops+1 <= k && newPrice < priceToReach[x.first]){
                priceToReach[x.first] = newPrice;
                q1.push({stops+1,{newPrice,x.first}});
            }
            else if(x.first == dst && newPrice < priceToReach[x.first]){
                priceToReach[x.first] = newPrice;
                q1.push({stops+1,{newPrice,x.first}});
            }
        }
    }
    if(priceToReach[dst] == INT_MAX){
        return -1;
    }
    return priceToReach[dst];
}
