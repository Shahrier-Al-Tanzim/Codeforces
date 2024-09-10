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
    int a, b; cin >> a >> b;
    int p = a, q = b;
    a = min(p, q), b = max(p, q);
    vector <int> bina, binb;
    while(a > 0) {
        bina.push_back(a % 2);
        a /= 2;
    }
    while(b > 0) {
        binb.push_back(b % 2);
        b /= 2;
    }
    while(bina.size() < binb.size()) bina.push_back(0);
    // vec_print(bina);
    // vec_print(binb);
    int cnt = 0;
    for(int i = 0; i < min(bina.size(), binb.size()); i++) {
        if(bina[i] != binb[i]) break;
        cnt++;
    }
    // if(cnt == min(bina.size(), binb.size()))
    // cnt++;
    int ans = (1 << cnt);
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
// 111001
// 100101

// 4 - 0100
// 8 - 1100
// 1 0010 1101 1110 0101 0101 1101 0001
// 0 0000 1101 1110 0101 1001 1101 0001
//     10 0000 0000 0000 0000 0000 0000