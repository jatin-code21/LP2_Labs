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
    int n;
    cin >> n;
    vector<pair<int, pair<char, int>>> v(n);
    int profit, deadline;
    char id;
    int mxDead = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        cin >> profit >> id >> deadline;
        v[i] = {profit, {id, deadline}};
        mxDead = max(mxDead, deadline);
    }
    sort(v.begin(), v.end(), greater<pair<int, pair<char, int>>>());
    vector<int> slot(mxDead, -1);
    int i = 0, j = 0;
    vector<char> ans;
    while (j != mxDead && i < n)
    {
        if (slot[v[i].second.second - 1] == -1)
        {
            slot[v[i].second.second - 1] = i;
            ans.push_back(v[i].second.first);
            j++;
        }   
        else
        {
            for (int k = v[i].second.second - 1; k >= 0; k--)
            {
                if (slot[k] == -1)
                {
                    slot[k] = i;
                    ans.push_back(v[i].second.first);
                    j++;
                    break;
                }
            }
        }
        i++;
    }
    for (auto it : ans)
    {
        cout << it << " ";
    }
}