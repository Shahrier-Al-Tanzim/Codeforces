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
    vector <int> ind(n);

    ind[n-1] = n;
    for(int i = n - 2; i >= 0; i--) {
        if(v[i] == v[i+1]) ind[i] = ind[i+1];
        else ind[i] = i + 1;
    }
    
    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        if(ind[l] > r) cout << "-1 -1" << endl;
        else cout << l + 1 << " " << ind[l] + 1 << endl;
    }
    // vec_print(ind)
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