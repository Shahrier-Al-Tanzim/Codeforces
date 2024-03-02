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
    vector <vector <int>> v(4);
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
    }
    for(int i = 1; i <= 3; i++) sort(all(v[i]));

    
    int high = v[2].front();
    int low  = v[1].back();
    int ans = high - low + 1;
    for(auto i : v[3]) {
        if(i >= low and i <= high) ans --;
    }

    cout << max(ans, 0ll) << endl;
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


