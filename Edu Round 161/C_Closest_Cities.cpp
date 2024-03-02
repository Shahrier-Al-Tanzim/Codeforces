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
    vector <int> v(n), pref(n); for(auto &i : v) cin >> i;
    vector <int> left(n), right(n);

    for(int i = 0; i < n - 1; i++) {
        right[i+1] = right[i];
        if(i == 0 or v[i] - v[i-1] > v[i+1] - v[i]) right[i+1]++;
        else right[i+1] += v[i+1] - v[i];
    }

    for(int i = n-1; i > 0; i--) {
        left[i-1] = left[i];
        if(i == n-1 or v[i] - v[i-1] < v[i+1] - v[i]) left[i-1]++;
        else left[i-1] += v[i] - v[i-1];
    }

    // vec_print(right);
    // vec_print(left);

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        l--, r--;
        if(l < r) cout << right[r] - right[l] << endl; 
        else cout << left[r] - left[l] << endl;
    }
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


