class Solution {
public:

    // Check if current color can be assigned to node
    bool isSafe(int node, int color,
                vector<vector<int>>& edges,
                vector<int>& nodeColor) {

        for (auto& edge : edges) {

            int u = edge[0];
            int v = edge[1];

            // Adjacent node already has same color
            if (u == node && nodeColor[v] == color)
                return false;

            if (v == node && nodeColor[u] == color)
                return false;
        }

        return true;
    }

    bool solve(int node,
               int totalNodes,
               vector<vector<int>>& edges,
               int totalColors,
               vector<int>& nodeColor) {

        // All nodes colored successfully
        if (node == totalNodes)
            return true;

        // Try every color
        for (int color = 1; color <= totalColors; color++) {

            if (isSafe(node, color, edges, nodeColor)) {

                nodeColor[node] = color;  // Assign color

                if (solve(node + 1, totalNodes,
                          edges, totalColors, nodeColor))
                    return true;

                nodeColor[node] = 0;      // Backtrack
            }
        }

        return false;
    }

    bool graphColoring(int V,
                       vector<vector<int>>& edges,
                       int m) {

        vector<int> nodeColor(V, 0);

        return solve(0, V, edges, m, nodeColor);
    }
};