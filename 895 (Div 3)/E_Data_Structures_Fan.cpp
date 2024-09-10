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
    string s; cin >> s;
    vector <int> pref(n+1);
    pref[0] = 0;
    for(int i = 0; i < n; i++) {
        pref[i+1] = pref[i] ^ v[i];
    }

    int x = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == '0') {
            x ^= v[i];
        }
    }

    
    int q; cin >> q;
    while(q--) {
        int t; cin >> t;
        if(t == 1) {
            int l, r; cin >> l >> r;
            l--;
            x ^= pref[r] ^ pref[l];
        } else {
            int g; cin >> g;
            if(g == 0) {
                cout << x << " ";
            } else {
                cout << (pref[n] ^ x) << " ";
            }
        }

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
