#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define fi first
#define se second

const int N = 1e5+10;
const int LOG = 20;
vector<vector<int>> up(N, vector<int>(LOG));
vector<vector<int>> g;
vector<int> depth;

void dfs(int u) {
    for(int v : g[u]) {
        up[v][0] = u;
        depth[v] = depth[u] + 1;
        for(int j = 1; j < LOG; ++j) {
            up[v][j] = up[up[v][j - 1]][j - 1];
        }
        dfs(v);
    }
}

int get_lca(int a, int b) {
    if(depth[a] < depth[b]) {
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    for(int j = LOG - 1; j >= 0; --j) {
        if(k & (1 << j)) {
            a = up[a][j];
        }
    }
    if(a == b) {
        return a;
    }
    for(int j = LOG - 1; j >= 0; --j) {
        if(up[a][j] != up[b][j]) {
            a = up[a][j];
            b = up[b][j];
        }
            }
    return up[a][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    g.resize(n);
    depth.resize(n);
    for(int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for(int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            g[i].push_back(x);
        }
    }
    dfs(0);
    int q;
    cin >> q;
    while(q--) {
        int a, b;
        cin >> a >> b;
        cout << get_lca(a, b) << '\n';
    }
    return 0;
}

