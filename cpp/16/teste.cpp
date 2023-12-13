#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calcula_num(ll n, char c) {
    if (c == '1' || c == '0') {
        n = ((n << 1) + (c - '0')) % 131071;
    }
    return n;
}

int main() {
    char c;
    ll n = 0;

    while (cin >> c) {
        if (c == '#') {
            cout << (n == 0 ? "YES\n" : "NO\n");
            n = 0;
        } else {
            n = calcula_num(n, c);
        }
    }
    
    return 0;
}