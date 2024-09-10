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
    map <pair<int, int>, int> left, right, mid;
    map <tuple<int, int, int>, int> all;

    for(int i = 0; i < n - 2; i++) {
        auto l = make_pair(v[i], v[i+1]);
        auto r = make_pair(v[i+1], v[i+2]);
        auto m = make_pair(v[i], v[i+2]);
        auto t = make_tuple(v[i], v[i+1], v[i+2]);
  
        left[l]++;
        right[r]++;
        mid[m]++;
        all[t]++;
    }

    int ans1 = 0, ans2 = 0, ans3 = 0, ans4 = 0;

    for(auto [_, d] : left) {
        ans1 += (d * (d - 1) >> 1);
    }
    for(auto [_, d] : right) {
        ans2 += (d * (d - 1) >> 1);
    }
    for(auto [_, d] : mid) {
        ans3 += (d * (d - 1) >> 1);
    }
    for(auto [_, d] : all) {
        ans4 += (d * (d - 1) >> 1);
    }

    cout << ans1 + ans2 + ans3 - 3 * ans4 << endl;

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
