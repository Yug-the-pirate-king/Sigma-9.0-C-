/*
QUESTION:
Given a weighted, undirected, and connected graph of V vertices and an adjacency list 'adj', where 'adj[i]' is a list of lists containing two integers where the first integer of each list j denotes there is an edge between node i and node j, and the second integer corresponds to the weight of that edge. You are also given the source vertex S. You need to find the shortest distance of all vertices from the source vertex S. You have to return a list of integers denoting the shortest distance between each node and the source vertex S.

APPROACH:
- We can use Dijkstra's algorithm to find the shortest distance from the source vertex to all other vertices in a weighted graph.
- The algorithm maintains a priority queue (min-heap) to store the vertices based on their tentative distances from the source vertex. We start with the source vertex and update the distances of its neighbors, pushing them into the priority queue.
- We continue this process until all vertices are visited and their distances are finalized. The priority queue ensures that we always pick the vertex with the minimum tentative distance for processing.
- We initialize the distance array 'dis' with a large value (infinity) for all vertices, except the source vertex whose distance is set to 0.
- We push the source vertex into the priority queue along with its distance, and then perform Dijkstra's algorithm.
- After the algorithm completes, we have the shortest distances of all vertices from the source vertex in the 'dis' array.

COMPLEXITY ANALYSIS:
- Time Complexity: O(E + log(V)), where E is the number of edges and V is the number of vertices in the graph. The time complexity is dominated by the priority queue operations in Dijkstra's algorithm.
- Space Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph. We use additional space for the adjacency list, the distance array, and the priority queue.
*/

vector<int> dijkstra(int n, vector<vector<int>> adj[], int s){
    vector<int> dis(n, 1e9);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dis[s] = 0;
    pq.push({0, s});

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        for(auto p : adj[u]){
            int v = p[0], wt = p[1]; 
            if(dis[u] + wt < dis[v]){
                dis[v] = dis[u] + wt;
                pq.push({dis[v], v});
            }
        }
    }

    return dis;
}
