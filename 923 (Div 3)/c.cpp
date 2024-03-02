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
    int n, m, k; cin >> n >> m >> k;
    vector <int> v1(n); for(auto &i : v1) cin >> i;
    vector <int> v2(m); for(auto &i : v2) cin >> i;
    set <int> s1, s2; 
    for(auto i : v1) if(i <= k) s1.insert(i);
    for(auto i : v2) if(i <= k) s2.insert(i);
    
    if(s1.size() >= k/2 and s2.size() >= k/2) {
        set <int> ans;
        for(auto i : s1) ans.insert(i);
        for(auto i : s2) ans.insert(i);

        if(ans.size() == k) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        cout << "NO" << endl;
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