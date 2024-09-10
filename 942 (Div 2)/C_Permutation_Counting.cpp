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
    int n, k; cin >> n >> k;
    vector <int> v(n+1); 
    // vector <pair <int, int>> vp;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    sort(all(v));
    // vec_print(v);
    int pref = 0, val = 0, ind = 0;
    int i = 0, cnt = 0;
    for(int i = 1; i <= n; i++) {
        int cost = (i - 1) * v[i] - pref;
        if(cost <= k) val = cost, ind = i; 
        else break;
        pref += v[i];
    }
    k -= val;
    val = v[ind];
    // cout << k << endl;
    for(int i = 1; i <= ind; i++) v[i] = val;
    // vec_print(v);
    int x = k / ind;
    for(int i = 1; i <= ind; i++) {
        v[i] += x;
        k-=x;
    }
    // vec_print(v);

    for(int i = ind; i > ind - k; i--) {
        v[i] ++;
    }
    // vec_print(v);

    int ans = n * v[1];
    for(int i = 1; i <= n; i++) {
        if(v[i] > v[1]) ans++;
    }

    ans = ans - n + 1;
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
