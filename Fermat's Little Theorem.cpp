#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MOD = (int)1e9+7;
const int maxN = (int)1e6+10;
ll F[maxN];

void preprocess() {
    F[0] = F[1] = 1;
    for(int i = 2; i < maxN; ++i) {
        F[i] = (F[i - 1] * i) % MOD;
    }
}

ll Exp(ll a, ll m) {
    if(m == 1LL) {
        return a;
    }
    ll res = Exp(a, m / 2);
    res %= MOD;
    res *= res;
    res %= MOD;
    if(m % 2 == 1) {
        res *= a;
        res %= MOD;
    }
    return res;
}

ll modInverse(ll a) {
    return Exp(a, MOD - 2);
}

ll nCr(int n, int r) {
    ll res = F[n];
    res *= modInverse(F[r]);
    res %= MOD;
    res *= modInverse(F[n - r]);
    res %= MOD;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    preprocess();
    int queries;
    cin >> queries;
    while(queries--) {
        int n, r;
        cin >> n >> r;
        cout << nCr(n, r) << endl;
    }
    return 0;
}

