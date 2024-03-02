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
    int k, x; cin >> k >> x;
    int total = 0;
    vector <int> v(n); for(auto &i : v) cin >> i, total += i;
    sort(v.rbegin(), v.rend());
    v.insert(v.begin(), 0);
    vector <int> pref(n+1);
    pref[1] = v[1]; 
    for(int i = 1; i <= n; i++) {
        pref[i] = pref[i-1] + v[i];
    }

    int Max = INT_MIN;
    // vec_print(v);
    // vec_print(pref);

    for(int i = 0; i <= k; i++) {
        Max = max(Max, pref[n] - 2 * pref[min(i+x,n)] + pref[i]);
    }

    cout << Max << endl;
    // 1 2 3 4 5 - 2 3
                
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


