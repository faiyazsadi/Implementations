#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int>> g, rg;
vector<bool> seen;
stack<int> stk;

void dfs(int u) {
    if(seen[u] == true) {
        return;
    }
    seen[u] = true;
    for(int v : g[u]) {
        dfs(v);
    }
    stk.push(u);
}

void reverseGraph() {
    for(int u = 0; u < n; ++u) {
        for(int v : g[u]) {
            rg[v].push_back(u);
        }
    }
}
    
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    g.resize(n);
    rg.resize(n);
    seen.resize(n);
    for(int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }
    reverseGraph();
    for(int i = 0; i < n; ++i) {
        dfs(i);
    }
    int numComps = 0;
    vector<int> ids(n, -1);
    queue<int> que;
    while(!stk.empty()) {
        int p = stk.top();
        stk.pop();
        if(ids[p] != -1) {
            continue;
        }
        que.push(p);
        ids[p] = numComps;
        cout << "Found Component " << numComps + 1 << ": ";
        while(!que.empty()) {
            int q = que.front();
            que.pop();
            cout << q + 1 << " ";
            for(int v : rg[q]) {
                if(ids[v] == -1) {
                    que.push(v);
                    ids[v] = numComps;
                }
            }
        }
        cout << "\n";
        numComps += 1;
    }
    return 0;
}

