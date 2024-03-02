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

int query(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int q; cin >> q;

    return q;
}

void solve() {
    int n, m; cin >> n >> m;
    int q1 = query(1, 1);

    int x_c = min(n, 1 + q1);
    int y_c = min(m, 1 + q1);
    
    pair <int, int> xy1 = {x_c, q1 + 2 - x_c}, xy2 = {q1 + 2 - y_c, y_c};

    int q2 =  query(xy1.first, xy1.second);
    int q3 =  query(xy2.first, xy2.second);

    pair <int, int> xy3 = {xy1.first - q2/2, xy1.second + q2/2};
    pair <int, int> xy4 = {xy2.first + q3/2, xy2.second - q3/2};

    int f = 0;
    if(xy3.first <= n and xy3.second <= m and q2 % 2 == 0) {
        int q4 = query(xy3.first, xy3.second);
        if(q4) f = 1;
    } else f = 1;

    if(f) cout << "! " << xy4.first << " " << xy4.second << endl;
    else  cout << "! " << xy3.first << " " << xy3.second << endl;
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
