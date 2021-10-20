#include <bits/stdc++.h>

using namespace std;

constexpr int N = (int) 1e6 + 10;
vector<int> primes;
bool is_prime[N + 1];

void sieve() {
    fill(is_prime, is_prime + N, true);
    for(int i = 3; i * i <= N; i += 2) {
        if(is_prime[i]) {
            for(int j = i * i; j <= N; j += i * 2) {
                is_prime[j] = false;
            }
        }
    }
    if(N > 1) primes.push_back(2);
    for(int i = 3; i <= N; i += 2) {
        if(is_prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    sieve();
    for(int prime : primes) {
        cout << prime << ' ';
    }
    cout << '\n';
    return 0;
}