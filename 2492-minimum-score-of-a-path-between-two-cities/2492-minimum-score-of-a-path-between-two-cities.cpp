class Solution {
public:
    vector<int> parent, size;
    void build(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
        return;
    }
    int find(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }

    void merge(int u, int v) {
        int up = find(u);
        int vp = find(v);

        if (up == vp)
            return;
        if (size[up] > size[vp]) {
            parent[vp] = up;
            size[up] += size[vp];
        } else {
            parent[up] = vp;
            size[vp] += size[up];
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        build(n);
        for (auto ed : roads) {
            int u = ed[0];
            int v = ed[1];
            merge(u, v);
        }

        int mini = INT_MAX;
        for (auto ed : roads) {
            if (find(ed[0]) == find(n) && find(ed[1]) == find(n)) {
                mini = min(mini, ed[2]);
            }
        }
        return mini;
    }
};
