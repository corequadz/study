#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;
using namespace std;


bool f(pair<ll, ll> a, pair<ll, ll> b) {
    return a.second > b.second;
}

int main() {
    ll n; cin >> n;
    ll day = 0;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; ++i) {
        ll val1, val2; cin >> val1 >> val2;
        v[i].first = val1;
        v[i].second = val2;
        day = max(day, val1);
    }
    ll res = 0;
    vector<bool> p(day+1,false);
    sort(v.begin(), v.end(), f);
    for (ll i = 0; i < n; ++i) {
        ll a = v[i].first;
        ll b = v[i].second;
        for (ll c = a; c >= 1; --c) {
            if (!p[c]) {
                p[c] = true;
                res += b;
                break;
            }
        }
    }
    cout << res;
}