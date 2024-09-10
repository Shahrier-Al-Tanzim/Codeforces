// C
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
    map <pair <int, int> , vector <int>> left, right, mid;
    // left
    for(int i = 0; i < n - 2; i++) {
        pair <int, int> p = {v[i], v[i+1]};
        left[p].push_back(v[i+2]);
    }
    // right
    for(int i = 0; i < n - 2; i++) {
        pair <int, int> p = {v[i+1], v[i+2]};
        right[p].push_back(v[i]);
    }
    // mid
    for(int i = 0; i < n - 2; i++) {
        pair <int, int> p = {v[i], v[i+2]};
        mid[p].push_back(v[i+1]);
    }

    // cout << "left " << endl;
    // for(auto [a, b] : left) {
    //     cout << a.first << ", " << a.second << " = ";
    //     vec_print(b);
    // }
    // cout << "=====" << endl;
    // cout << "RIGHT" << endl;
    // for(auto [a, b] : right) {
    //     for(auto i : b) cout << i << " ";
    //     cout << "= " << a.first << ", " << a.second << endl;
    // }
    // cout << "=====" << endl;
    // cout << "MID " << endl;
    // for(auto [a, b] : mid) {
    //     cout << a.first << " = ";
    //     for(auto i : b) cout << i << " ";
    //     cout << "= " << a.second << endl;
    // }

    int ans1 = 1, ans2 = 1, ans3 = 1;
    int ans_l = 0, ans_r = 0, ans_m = 0;
    map <int, int> f_left, f_right, f_mid;
    for(auto [a, b] : left) {
        for(auto i : b) {
            f_left[i]++;
        }
        if(f_left.size() >= 2) {
            ans1 = 1;
            for(auto [x, y] : f_left) ans1 *= y;
            ans_l += ans1;
        }
        f_left.clear();
    }
    for(auto [a, b] : right) {
        for(auto i : b) {
            f_right[i]++;
        }

        if(f_right.size() >= 2) {
            ans2 = 1;
            for(auto [x, y] : f_right) ans2 *= y;
            ans_r += ans2;
        }
        f_right.clear();
    }
    for(auto [a, b] : mid) {
        for(auto i : b) {
            f_mid[i]++;
        }

        if(f_mid.size() >= 2) {
            ans3 = 1;
            for(auto [x, y] : f_mid) ans3 *= y;
            ans_m += ans3;
        }
        f_mid.clear();
    }
    // cout << ans_l << " " << ans_r <<" " << ans_m << endl; 
    cout << ans_l + ans_r + ans_m << endl;
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
