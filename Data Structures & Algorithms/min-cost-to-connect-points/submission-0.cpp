const int MAXN = 1e5 + 5;
    int par[MAXN], sz[MAXN];

class Solution {
public:
    


    void init(int n)
    {
        for (int i = 0; i < n; i++) par[i] = i, sz[i] = 1;
    }

    int find(int x) {
        while (par[x] != x) {
            par[x] = par[par[x]]; // path halving
            x = par[x];
        }
        return x;
    }

    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (sz[a] < sz[b]) swap(a, b);
        par[b] = a;
        sz[a] += sz[b];
        return true;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        int n = points.size();
        init(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int weight = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                vector<int> inf = {weight, i , j};
                edges.push_back(inf);
            }
        }

        sort(edges.begin(), edges.end());
        int finalCost = 0;
        for (int i = 0; i < edges.size(); i++)
        {
            int v = edges[i][1];
            int u = edges[i][2];
            int w = edges[i][0];
            if (find(v) == find(u)) continue;
            unite(u,v);
            finalCost += w;
        }

        return finalCost;
    }
};
