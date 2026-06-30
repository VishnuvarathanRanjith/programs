class Solution {
public:
    long long recur(int node, vector<int>& vis, vector<vector<int>>& adj,
                    int k, long long& count, vector<int>& values) {

        vis[node] = 1;
        long long sum = values[node];

        for (int neigh : adj[node]) {
            if (!vis[neigh]) {
                long long childSum = recur(neigh, vis, adj, k, count, values);
                sum += childSum;
            }
        }

        if (sum % k == 0) {
            count++;
            return 0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges,
                                vector<int>& values, int k) {

        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> vis(n, 0);
        long long count = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                recur(i, vis, adj, k, count, values);
            }
        }

        return count;
    }
};
