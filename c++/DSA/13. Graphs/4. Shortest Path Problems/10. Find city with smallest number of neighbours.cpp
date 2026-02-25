/* QUESTION:

There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold. If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

Example:

Input: n = 4, edges = [[0, 1, 3], [1, 2, 1], [1, 3, 4], [2, 3, 1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph.
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2]
City 1 -> [City 0, City 2, City 3]
City 2 -> [City 0, City 1, City 3]
City 3 -> [City 1, City 2]
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

APPROACH:
- We will use Dijkstra's algorithm to find the shortest distances from each city to all other cities in the graph.
- For each city, we will find the count of cities that are reachable through some path and whose distance is at most distanceThreshold.
- We will keep track of this count for each city in a map.
- Finally, we will find the city with the smallest count, and if there are multiple such cities, we will return the city with the greatest number.

COMPLEXITY ANALYSIS:
- The time complexity of Dijkstra's algorithm is O(V^2), where V is the number of cities.
- Since we perform Dijkstra's algorithm for each city, the overall time complexity is O(V^3).
- The space complexity is O(V) for storing the distances and the count of reachable cities for each city.

CODE:
*/

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    vector<pair<int, int>> adj[n];
    for (auto e : edges) {
        adj[e[0]].push_back({e[1], e[2]});
        adj[e[1]].push_back({e[0], e[2]});
    }

    vector<int> dis(n, numeric_limits<int>::max());
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++) {
        dis[i] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});

        while (!pq.empty()) {
            auto [uwt, u] = pq.top();
            pq.pop();

            for (auto [v, vwt] : adj[u]) {
                if (dis[v] > uwt + vwt) {
                    dis[v] = uwt + vwt;
                    pq.push({dis[v], v});
                }
            }
        }

        int nbrCnt = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && dis[j] <= distanceThreshold)
                nbrCnt++;
            dis[j] = numeric_limits<int>::max();
        }
        mp[i] = nbrCnt;
    }

    int mini = numeric_limits<int>::max(), ans = 0;
    for (int i = 0; i < n; i++) {
        if (mp[i] < mini) {
            mini = mp[i];
            ans = i;
        } else if (mp[i] == mini)
            ans = max(ans, i);
    }

    return ans;
}
