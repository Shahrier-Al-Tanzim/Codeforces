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
    int ans = n * (n + 1) / 2;
    vector <int> pos;

    int cnt = 0;
    for(auto i : v) {
        if(i % 2 == 0) {
            pos.push_back(cnt);
            cnt = 0;
        } else cnt++;
    }
    if(cnt) pos.push_back(cnt);
    sort(all(pos));
    // vec_print(pos);
    int Max = pos.back();
    pos.pop_back();
    pos.push_back(Max / 2); 
    pos.push_back((Max - 1) / 2);

    for(auto i : pos) {
        ans -= i * (i + 1) / 2;
    } 

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
