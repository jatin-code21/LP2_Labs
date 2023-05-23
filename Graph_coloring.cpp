#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt",
            "r", stdin);
    freopen("output.txt",
            "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<int> adj[n];
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    } // Adjacency List
    vector<bool> availabeColor(n, false);
    vector<int> color(n, -1);
    set<int> st;
    color[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto it : adj[i])
        {
            if (color[it] != -1)
            {
                availabeColor[color[it]] = true;
            }
        }
        int j;
        for (j = 0; j < n; j++)
        {
            if (availabeColor[j] == false)
            {
                break;
            }
        }
        color[i] = j;
        for (auto it : adj[i])
        {
            if (color[it] != -1)
            {
                availabeColor[color[it]] = false;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << color[i] << " ";
    }
    for (int i = 0; i < n; i++)
    {
        st.insert(color[i]);
    }
    cout << "\n"
         << st.size();
}