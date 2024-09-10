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

bool f(vector <int> &v) {
    vector <int> d(v.size() - 1);
    for(int i = 0; i < v.size() - 1; i++) {
        d[i] = __gcd(v[i], v[i+1]);
    }
    // vec_print(d);
    return is_sorted(all(d));
}

void solve() {
    int n; cin >> n;
    vector<int> v(n); for(auto &i : v) cin >> i;
    vector <int> d(n - 1);
    for(int i = 0; i < n - 1; i++) {
        d[i] = __gcd(v[i], v[i+1]);
    }

    // vec_print(d);
    int cnt = 0;
    for(int i = 0; i < d.size() - 1; i++) {
        if(d[i] > d[i+1]) cnt++;
    }
    if(cnt > 2) {
        cout << "NO" << endl;
        return;
    }

    if(cnt == 0) {cout << "YES" << endl; return;}
    int ind_l = -1, ind_m = -1, ind_r = -1;
    
    for(int i = 0; i < d.size() - 1; i++) {
        if(d[i] > d[i+1]) {
            ind_l = i -1;
            ind_m = i;
            ind_r = i+1;
            break;
        }
    }
    // cout << ind_l << " " << ind_m << " " << ind_r << endl;
    if(ind_l >= 0) {
        vector <int> ans = v;
        ans.erase(ans.begin() + ind_l);
        if(f(ans)) {cout << "YES" << endl; return;}
    }
    if(ind_m >= 0) {
        vector <int> ans = v;
        ans.erase(ans.begin() + ind_m);
        if(f(ans)) {cout << "YES" << endl; return;}
    }

    if(ind_r < n) {
        vector <int> ans = v;
        ans.erase(ans.begin() + ind_r);
        if(f(ans)) {cout << "YES" << endl; return;}
    }
    if(ind_r + 1 < n) {
        vector <int> ans = v;
        ans.erase(ans.begin() + ind_r+1);
        if(f(ans)) {cout << "YES" << endl; return;}
    }
    if(ind_r + 2 < n) {
        vector <int> ans = v;
        ans.erase(ans.begin() + ind_r+2);
        if(f(ans)) {cout << "YES" << endl; return;}
    }

    cout << "NO" << endl;
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


