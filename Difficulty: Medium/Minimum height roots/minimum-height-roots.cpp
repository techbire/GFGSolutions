class Solution {
public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        if(V == 1) return {0};

        vector<vector<int>> adj(V);
        vector<int> deg(V, 0);

        // build graph
        for(auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }

        queue<int> q;

        // push all leaves
        for(int i = 0; i < V; i++) {
            if(deg[i] == 1) q.push(i);
        }

        int rem = V;

        // remove layer by layer
        while(rem > 2) {
            int sz = q.size();
            rem -= sz;

            while(sz--) {
                int u = q.front(); q.pop();

                for(auto v : adj[u]) {
                    deg[v]--;
                    if(deg[v] == 1) {
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;
        while(!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};