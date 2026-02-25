/*
QUESTION:-
You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection, and that there is at most one road between any two intersections.

You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.

Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 10^9 + 7.

Approach:
1. We can use Dijkstra's algorithm to find the shortest path from intersection 0 to intersection n-1 and also keep track of the number of ways to reach each intersection in the shortest time.
2. We start with intersection 0 and keep track of the minimum time required to reach each intersection.
3. During the process, we also keep track of the number of ways to reach each intersection in the shortest time.
4. If we find a shorter path to a particular intersection, we update its minimum time and reset the number of ways to reach that intersection to the number of ways to reach the previous intersection.
5. If we find an equal time path to a particular intersection, we add the number of ways to reach the previous intersection to the number of ways to reach the current intersection.

Complexity Analysis:
- Let n be the number of intersections and E be the number of roads in the input.
- Dijkstra's algorithm has a time complexity of O((n+E)log(n)) using a priority queue.
- The space complexity is O(n) to store the distance and ways arrays.
*/

#include <vector>
#include <queue>
using namespace std;

int countPaths(int n, vector<vector<int>>& roads) {
    vector<pair<int, int>> adj[n];
    for (auto road : roads) {
        adj[road[0]].push_back({ road[1], road[2] });
        adj[road[1]].push_back({ road[0], road[2] });
    }
    
    int mod = 1e9 + 7;
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> pq;
    vector<long long int> dis(n, 1e18);
    vector<long long int> ways(n);
    
    dis[0] = 0;
    ways[0] = 1;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
        auto [uwt, u] = pq.top();
        pq.pop();

        for (auto [v, vwt] : adj[u]) {
            if (dis[v] > uwt + vwt) {
                ways[v] = ways[u];
                dis[v] = uwt + vwt;
                pq.push({ dis[v], v });
            }
            else if (dis[v] == uwt + vwt) {
                ways[v] = (ways[v] + ways[u]) % mod;
            }
        }
    }

    int ans = ways[n - 1] % mod;
    return ans;
}
