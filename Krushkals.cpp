#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0); // rank is the height of the tree
        parent.resize(n + 1);  // using the one based indexing
        size.resize(n + 1, 1); // size is the number of nodes in the tree
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int findUltiParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findUltiParent(parent[node]);
        // this is the path compression
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUltiParent(u);
        int ulp_v = findUltiParent(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUltiParent(u);
        int ulp_v = findUltiParent(v);
        if (ulp_u == ulp_v)
        {
            return;
        }
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n, vector<pair<int, int>>());
    int u, v, wt;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> wt;
        graph[u].push_back({v, wt});
        graph[v].push_back({u, wt});
    }
    vector<pair<int, pair<int, int>>> edges;
    // O(E + V)
    for (int i = 0; i < n; i++)
    {
        for (auto it: graph[i])
        {
            int wt = it.second;
            int adjnode = it.first;
            int node = i;
            edges.push_back({wt, {node, adjnode}});
        }
    }
    int mstWt = 0;
    sort(edges.begin(), edges.end());
    // O(nlogm)
    DisjointSet ds(n);
    // O(E * 4*aplha) -> 4*alpha is of disjoint set
    for (auto it: edges)
    {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

        if (ds.findUltiParent(u) != ds.findUltiParent(v))
        {
            ds.unionBySize(u, v);
            mstWt += wt;
        }
    }
}