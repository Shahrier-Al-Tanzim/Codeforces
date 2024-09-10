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
    int n, k, q; cin >> n >> k >> q;
    vector <int> a(k); for(auto &i : a) cin >> i;
    vector <int> b(k); for(auto &i : b) cin >> i;
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    k++;
    map <int, int> mp;
    for(int i = 0; i < k; i++) {
        mp[a[i]] = b[i];
    }

    // map_print(mp);
    // vec_print(a);
    while(q--) {
        int x; cin >> x;
        double ans = 0;
        auto it = lower_bound(all(a), x);
        if(*it != x) it--;
        // cerr << *it << endl;
        ans += mp[*it];
        if(x == 0 or x == n) {
            cout << ans << " ";
            continue;
        }  
        int l = *it, r = *(++it);
        // cout << "l = " << l << ", r = " << r << endl;
        // cout << "mp[l] = " << mp[l] << ", mp[r] = " << mp[r] << endl;
        // cout << "Hz = " << Hz << endl;
        double Hz = double(mp[r] - mp[l]) / double(r - l);
        x -= l;  
        ans += x * Hz;
        cout << fixed << setprecision(0) << floor(ans) << " ";
    }
    nl;
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
