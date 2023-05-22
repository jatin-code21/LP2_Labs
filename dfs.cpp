#include <bits/stdc++.h>
using namespace std;

// const int N = 1e5 + 5;
void dfs(int source, vector<vector<int>> &g, vector<bool> &vis)
{
    cout << source << " ";
    vis[source] = true;
    for (auto child : g[source])
    {
        if (vis[child])
            continue;
        dfs(child, g, vis);
    }
    return;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n, m, source;
    cin >> n >> m >> source;
    vector<vector<int>> g(n + 1);
    vector<bool> vis(n + 1, false);
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    dfs(source, g, vis);
}