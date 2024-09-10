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
    int n; cin >> n;
    vector <int> v(n); for(auto &i : v) cin >> i; 
    v.insert(v.begin(), 0);
    vector <int> mx(23), pre(23);
    int OR = 0;
    for(int i = 1; i <= n; i++) {
        OR |= v[i];
        for(int j = 0; j < 22; j++) {
            // if j-th bit is on
            if(v[i] & (1ll << j)) {
                mx[j] =  max(i - pre[j], mx[j]);
                pre[j] = i;
            }
        }
    }

    int ans = 1;
    for(int i = 0; i < 22; i++) {
        if(OR & (1ll << i)) {
            // mx[i] = max(mx[i], n + 1 - pre[i]);
            // ans = max(ans, mx[i]);

            ans = max(ans, max(mx[i], n + 1 - pre[i]));
        }
    }

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
