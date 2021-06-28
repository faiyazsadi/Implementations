#include <bits/stdc++.h>

using namespace std;

class BinaryLifting {
    // Assumes parent[i] < i
    int LOG;
    vector<vector<int>> up;
    vector<int> depth;
public:
    BinaryLifting(int N, vector<int>& parent) {
        LOG = 0;
        while((1 << LOG) <= N) {
            LOG += 1;
        }
        up = vector<vector<int>> (N, vector<int> (LOG));
        depth = vector<int> (N);
        parent[0] = 0;
        for(int v = 0; v < N; ++v) {
            up[v][0] = parent[v];
            if(v != 0) {
                depth[v] = depth[parent[v]] + 1;
            }
            for(int j = 1; j < LOG; ++j) {
                up[v][j] = up[ up[v][j - 1] ][j - 1];
            }
        }
    }
    int getKthAncestor(int node, int k) {
        if(depth[node] < k) {
            return -1;
        }
        for(int j = 0; j < LOG; ++j) {
            if(k & (1 << j)) {
                node = up[node][j];
            }
        }
        return node;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    return 0;
}

