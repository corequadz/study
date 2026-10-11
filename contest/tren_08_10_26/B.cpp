#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main () {
    ll n; cin >> n;
    if (n < 3) {
        cout << n << endl;
    } else {
        cout << n * (n - 1) * (n - 2) << endl;
    }
    return 0;
}