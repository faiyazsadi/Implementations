#include <bits/stdc++.h>

using namespace std;

const int N = (int) 5e5+10;
const int LOG = 25;
vector<vector<int>> sp(N, vector<int>(LOG));

void init(int n) {
    for(int j = 1; j < LOG; ++j) {
        for(int i = 0; i + (1 << j) - 1 < n; ++i) {
            sp[i][j] = min(sp[i][j - 1], sp[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int query() {
    int l, r;
    cin >> l >> r;
    r--;
    int len = r - l + 1;
    int k = 31 - __builtin_clz(len);
    return min(sp[l][k], sp[r - (1 << k) + 1][k]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("in.txt", "r", stdin);
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        sp[i][0] = a[i];
    }
    init(n);
    while(q--) {
        int ans = query();
        cout << ans << '\n';
    }
    return 0;
}

