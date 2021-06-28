#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define fi first
#define se second

int root, tyme;
vector<vector<int>> g;
vector<int> dis, low, vis, par, cutpoints;

void dfs(int u) {
    tyme++;
    dis[u] = low[u] = tyme;
    vis[u] = true;
    int no_of_children = 0;
    for(int v : g[u]) {
        if(v == par[u]) {
            continue;
        }
        if(vis[v] == true) {
            low[u] = min(low[u], dis[v]);
        }
        if(vis[v] == false) {
            par[u] = v;
            dfs(v);
            low[u] = min(low[u], low[v]);
            if(u != root and dis[u] <= low[v]) {
                cutpoints.push_back(u + 1);
            }
            no_of_children += 1;
        }
    }
    if(u == root and no_of_children > 1) {
        cutpoints.push_back(u + 1);
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    dis.resize(n);
    vis.resize(n, false);
    low.resize(n);
    par.resize(n);
    for(int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    root = 1;
    root--;
    dfs(root);
    cout << "Articulation Points are: " << '\n';
    for(int x : cutpoints) {
        cout << x << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "r", stdin);
    solve();
    return 0;
}

