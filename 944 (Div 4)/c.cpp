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
bool doIntersect(int a, int b, int c, int d) {
    // If a and b are on opposite sides of c and d, they intersect
    return (a < c && c < b && b < d) || (c < a && a < d && d < b);
}

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    vector <int> r1, r2;
    for(int i = min(a, b); i <= max(a, b); i++) r1.push_back(i);
    for(int i = max(a, b); i <= min(a, b) + 12; i++) {
        int x = (i % 12);
        if(x == 0) x = 12;
        r2.push_back(x);
    }
    sort(all(r1)); sort(all(r2));
    // vec_print(r1);
    // vec_print(r2);

    int f = 0;
    for(auto i : r1) {
        if(i == c) f++;
        if(i == d) f++;
    }
    if(f == 2) {cout << "NO" << endl; return;}
    if(f == 1) {cout << "YES" << endl; return;}
    for(auto i : r2) {
        if(i == c) f++;
        if(i == d) f++;
    }
    if(f == 2) {cout << "NO" << endl; return;}
    else cout << "YES" << endl;
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
