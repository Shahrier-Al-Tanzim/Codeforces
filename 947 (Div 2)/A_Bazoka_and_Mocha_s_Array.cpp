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
    vector<int> v(n); for(auto &i : v) cin >> i;
    // v.push_back(v.back());
    vector <int> t, s;
    int f = 0;
    t.push_back(v.front());
    for(int i = 1; i < n; i++) {
        if(v[i-1] <= v[i] and f == 0) t.push_back(v[i]);
        else {
            f = 1;
            s.push_back(v[i]);
        }
    }

    // vec_print(t);
    // vec_print(s);
    vector <int> ans;
    for(auto i : s) ans.push_back(i);
    for(auto i : t) ans.push_back(i);

    if(is_sorted(all(ans))) cout << "Yes" << endl;
    else cout << "No" << endl;
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
