#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct BIT {
    int n;
    vector<ll> a;

    void build(int s) {
        a = vector<ll>(s, 0);
        n = s;
    }

    void add(int loc, ll x) {
        while (loc < n) {
          a[loc] += x;
          loc = loc | (loc + 1);
        }
    }

    ll query(int loc) {
        ll sum = 0;
        while (loc >= 0) {
            sum += a[loc];
            loc = (loc & (loc + 1)) - 1;
        }
        return sum;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, Q;
    cin >> N >> Q;
    BIT bit;
    bit.build(N);
    for(int i = 0; i < N; ++i) {
        ll x;
        cin >> x;
        bit.add(i, x);
    }
    for(int i = 0; i < Q; ++i) {
        int type; cin >> type;
        if(type == 0) {
            int p;
            ll x;
            cin >> p >> x;
            bit.add(p, x);
        }
        else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            ll ans = bit.query(r) - bit.query(l);
            cout << ans << '\n';
        }
    }
    return 0;
}
