class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        
        vector<vector<pair<int,int>>> adj(V);
        
        for(auto &e : edges){
            int u = e[0], v = e[1], wt = e[2];
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }

        vector<long long> dist(V, LLONG_MAX);
        vector<int> ways(V, 0);
        
        priority_queue<
            pair<long long,int>, 
            vector<pair<long long,int>>, 
            greater<pair<long long,int>>
        > pq;

        int mod = 1e9+7;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0,0});

        while(!pq.empty()){
            auto [d, node] = pq.top();
            pq.pop();

            if(d > dist[node]) continue;

            for(auto &[v, wt] : adj[node]){
                
                if(d + wt < dist[v]){
                    dist[v] = d + wt;
                    ways[v] = ways[node];
                    pq.push({dist[v], v});
                }
                else if(d + wt == dist[v]){
                    ways[v] = (ways[v] + ways[node]) % mod;
                }
            }
        }

        return ways[V-1] % mod;
    }
};