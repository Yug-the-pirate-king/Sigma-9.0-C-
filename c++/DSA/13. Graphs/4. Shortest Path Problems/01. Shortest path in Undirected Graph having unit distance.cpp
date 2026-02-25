/*
QUESTION:
You are given an undirected graph with unit weight. Find the shortest path from the source vertex to all other vertices, and if it is unreachable to reach any vertex, then return -1 for that vertex.

APPROACH:
- To find the shortest path from the source vertex to all other vertices, we can use a BFS traversal of the graph.
- We create an adjacency list to represent the undirected graph.
- We use a queue to perform the BFS traversal, starting from the source vertex.
- During the BFS traversal, we keep track of the level (or distance) of each vertex from the source vertex.
- We maintain a boolean array to keep track of visited vertices so that we don't visit the same vertex again.
- If a vertex is reachable from the source vertex, its distance will be equal to the number of edges in the shortest path from the source vertex.
- After the BFS traversal is complete, we will have the distance of each vertex from the source vertex.

COMPLEXITY ANALYSIS:
- Time Complexity: O(N+M), where N is the number of vertices and M is the number of edges in the graph. We perform a BFS traversal, visiting each vertex and edge once.
- Space Complexity: O(N), where N is the number of vertices. We use additional space to store the adjacency list, visited array, and the distance array.
*/

vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src){
    vector<int> adj[N];
    for(auto e:edges){
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }
    
    vector<bool> vis(N);
    vector<int> dis(N, -1);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    
    int lvl = 0;
    while(!q.empty()){
        int siz = q.size();
        while(siz--){
            int node = q.front();
            q.pop();
            dis[node] = lvl;
            for(auto v:adj[node]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        lvl++;
    }
    
    return dis;
}
