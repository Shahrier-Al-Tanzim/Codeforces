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
    map <int, int> mp;
    for(int i = 0; i < n; i++) mp[i] = 1;
    int coins = n;
    set <pair <int, int>> st;
    for(int i = 0; i < n; i++) {
        st.insert({v[i], i});
    }
    // cout << (st.begin()->first) << endl;
    int cnt = 0;
    while(st.begin()->first <= coins) {
        cnt++;
        int mul = st.begin() -> first;
        int ind = st.begin() -> second;
        int old_coin = mul / v[ind];

        st.erase(st.begin());

        int x = coins / v[ind]; x++;
        // if(v[ind] * x <= coins) x++;

        int new_coins = x;
        int new_mul = new_coins * v[ind];
        // int old_coins = mp[ind];

        int diff = new_coins - old_coin;

        mp[ind] = new_mul;
        
        coins += diff;
        // cout << c_ << " " << coins << endl;
        st.insert({new_mul, ind});

        // for(auto [a, b] : st) {
        //     cout << "{" << a << ", " << v[b] << "}, ";
        // }
        // nl;
    }
    // nl;
    vector <int> ans(n);
    for(auto [a, b] : st) {
        // cout << a / v[b] << " ";
        ans[b] = a / v[b];
    }
    // nl;

    vec_print(ans);
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
