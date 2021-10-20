#include <bits/stdc++.h>

using namespace std;

constexpr int N = (int) 1e6 + 10;
vector<int> prime;
bool is_composite[N];

void sieve() {
    fill (is_composite, is_composite + N, false);
    for (int i = 2; i < N; ++i) {
        if (!is_composite[i]) prime.push_back (i);
        for (int j = 0; j < (int) prime.size () and i * prime[j] < N; ++j) {
            is_composite[i * prime[j]] = true;
            if (i % prime[j] == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve();
    return 0;
}

