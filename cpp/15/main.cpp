#include <iostream>
#include <math.h>

using namespace std;
typedef long long ll;
ll MAX = 1e9+7;

ll a, b, c, res, aux;
int n;

ll power(ll base, ll ex) {
    if (ex == 0) return base;
    ll aux = base;
    for (int i = 0; i < ex-1; i++) {
        aux = (aux * ex) % MAX;
        // cout << "alo\n";
    }

    return aux; 
}

double solve(double n1, double n2) {
    return power(n1, n2);
}

int main() {
    cin >> n;
    // cout << n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        // res = solve(b , c);
        aux = solve(a , solve(b, c));
        cout << aux << endl;
    }
    return 0;
}