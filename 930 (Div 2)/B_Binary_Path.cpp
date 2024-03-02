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
    vector <string> v(2); 
    cin >> v[0]  >> v[1];
    string ans = "";
    ans += v[0][0];

    int f = 0;
    int l = 0, r = n-1;
    for(int i = 0; i < n - 1; i++) {
        if(f) ans += v[1][i];
        else if(v[0][i+1] > v[1][i]) {
            ans += v[1][i];
            f = 1;
            r = i;
        } 
        else if(v[0][i+1] < v[1][i]) {
            ans += v[0][i+1];
            l = i + 1;
        } else ans += v[0][i+1];
    }

    ans += v[1].back();
    
    cout << ans << endl;
    cout << r - l + 1 << endl;
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