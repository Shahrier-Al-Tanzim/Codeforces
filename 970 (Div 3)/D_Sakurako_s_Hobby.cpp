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
    // vec_print(v);
    int vis[n+1] = {0}, b[n+1] = {0};
    // vec_print(v);
    // vec_print(b);
    for(int j = 1; j <= n; j++) {
        if(vis[j]) continue;

        int cnt = 0;        
        while(!vis[j]) {
            vis[j] = 1;
            cnt += s[j - 1] == '0';
            j = v[j - 1];
        }

        while(vis[j] != 2) {
            vis[j] = 2;
            b[j] = cnt;
            j = v[j - 1];
        }
    }

    for(int i = 1; i <= n; i++) cout << b[i] << " ";
    nl;
}   

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(NULL);
    int t = 1;x
    cin >> t; 
    for(int i = 1; i <= t; i++) {
    // while(t--) {
        // cout << "Case " << i << ":" << endl;
        solve();
    }
}
