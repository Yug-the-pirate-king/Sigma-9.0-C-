/* QUESTION:

There are n cities connected by some number of flights. You are given an array flights where flights[i] = [fromi, toi, pricei] indicates that there is a flight from city fromi to city toi with cost pricei.

You are also given three integers src, dst, and k, return the cheapest price from src to dst with at most k stops. If there is no such route, return -1.

Example:

Input: n = 4, flights = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]], src = 0, dst = 3, k = 1
Output: 700
Explanation:
The graph is shown above.
The optimal path with at most 1 stop from city 0 to 3 is marked in red and has cost 100 + 600 = 700.
Note that the path through cities [0,1,2,3] is cheaper but is invalid because it uses 2 stops.

APPROACH:
- We can use Breadth-First Search (BFS) to find the cheapest price from the source to the destination with at most k stops.
- We will create an adjacency list to represent the graph, where each node will have a list of neighboring nodes with their corresponding prices.
- We will use a queue to perform BFS starting from the source node.
- During BFS, we will keep track of the distance to each node and the number of stops made so far.
- If we reach the destination node and the number of stops is less than or equal to k, we will update the minimum cost to reach the destination.
- Continue BFS until we have explored all possible paths with at most k stops.
- Return the minimum cost to reach the destination if it is reachable, otherwise return -1.

COMPLEXITY ANALYSIS:
- The time complexity is O(n*k) since we can have at most k stops and for each stop, we will explore all n nodes.
- The space complexity is O(n) to store the distance values.

CODE:
*/


int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int, int>>> adj(n);
    for (auto flight : flights) {
        adj[flight[0]].push_back({flight[1], flight[2]});
    }

    queue<pair<int, int>> q;
    q.push({src, 0});

    vector<int> dis(n, 1e9);

    int stops = 0;
    while (!q.empty() && stops <= k) {
        int size = q.size();
        while (size--) {
            auto [u, uwt] = q.front();
            q.pop();
            for (auto& [v, vwt] : adj[u]) {
                if (vwt + uwt < dis[v]) {
                    dis[v] = uwt + vwt;
                    q.push({v, dis[v]});
                }
            }
        }
        stops++;
    }
    if (dis[dst] == 1e9)
        return -1;
    return dis[dst];
}
