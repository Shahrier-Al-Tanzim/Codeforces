// "In the name of Allah, most gracious and most merciful"
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

template<typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define int long long
#define el "\n"
#define nl cout << "\n";
#define stp setprecision
#define fixed_stp fixed << setprecision
#define vec_print(v) for  (auto itr : v) cout << itr << " "; nl;
#define map_print(v) for  (auto [it1, it2] : v) cout << it1 << " " << it2 << endl;
#define fio ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define pi 2 * acos(0.0)
#define all(v) v.begin(), v.end() 

void solve() {
    int a, b, c; cin >> a >> b >> c;
    int x = a - a % 2;
    int ans = 0;
    ans += x * 3 / 2; 
    int ans2 = ans;
    a -= x, b -= x, c -= x;
    int aa = a, bb = b, cc = c;
    c -= a; 
    ans += a;
    a = 0;
    // cout << a << " " << b << " " << c << endl;
    if(b > c) swap(b, c);
    c -= b; 
    ans += b;
    b = 0;
    // cout << a << " " << b << " " << c << endl;

    // if(c % 2 == 1) cout << -1 << endl;
    // else cout << ans << endl;
    if(c % 2 == 1) ans = -1;

    ans2 += aa;
    bb -= aa;
    ans2 += bb;
    cc -= bb;
    if(cc % 2 == 1) ans2 = -1;

    cout << max(ans, ans2) << endl;
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