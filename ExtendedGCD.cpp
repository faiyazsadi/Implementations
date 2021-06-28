#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

#define fi first
#define se second

struct ExtendedGCD {
    int recur(int a, int b, int& x, int& y) {
        if(b == 0) {
            x = 1;
            y = 0;
            return a;
        }
        int x1, y1;
        int d = recur(b, a % b, x1, y1);
        x = y1;
        y = x1 - (a / b) * y1;
        return d;
    }
    int iter(int a, int b, int& x, int & y) {
        int x1 = 0, y1 = 1;
        while(b > 0) {
            int q = a / b;
            tie(x, x1) = make_tuple(x1, x - q * x1);
            tie(y, y1) = make_tuple(y1, y - q * y1);
            tie(a, b) = make_tuple(b, a - q * b);
        }
        return a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    int x = 1, y = 0;
    ExtendedGCD gcd;
    int g = gcd.iter(a, b, x, y);
    cout << "gcd: " << g << '\n';
    cout << "co-efficients: " << '\n';
    cout << "x: " <<  x << ' ' << "y: " << y << '\n';
    return 0;
}

