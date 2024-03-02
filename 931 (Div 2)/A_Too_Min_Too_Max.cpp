// "In the name of Allah, most gracious and most merciful"
#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cerr << (#x) << " = " << x << endl;
#define int long long
#define ll long long
#define el "\n"
#define nl cout << "\n";
#define all(v) v.begin(), v.end()
#define vec_print(v) \
    for (auto itr : v) cout << itr << " "; cout << endl;
#define vec_print_err(v) \
    for (auto itr : v) cerr << itr << " "; cerr << endl;

void solve() {
    int n; cin >> n;
    vector <int> v(n); for(auto &i : v) cin >> i;
    sort(all(v));
    // vec_print(v);

    int i = v[0], k = v[1], l = v[n-2], j = v[n-1];
    int ans = abs(i - j) + abs(j - k) + abs(k - l) + abs (l - i);
    cout << ans << endl;
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    
    int t = 1;
    cin >> t; 
    for(int i = 1; i <= t; i++) {
    // while(t--) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
} 