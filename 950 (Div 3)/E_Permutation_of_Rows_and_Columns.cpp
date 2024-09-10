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
    int n, m; cin >> n >> m;
    vector <int> v1[n], v2[n];
    map <int, pair <int, int>> mp1, mp2;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int a; cin >> a;
            v1[i].push_back(a);
            mp1[a] = {i, j};
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int a; cin >> a;
            v2[i].push_back(a);
            mp2[a] = {i, j};
        }
    }
    
    int f = 0;
    // cout << "row = " << endl;
    for(int i = 0; i < n; i++) {
        int p = v2[i][0];
        // int k = mp1[p].first;
        int k = mp1[p].first - mp2[p].first;
        // cout << "p , k = " << p << " " << k  << endl;
        for(int j = 0; j < m; j++) {
            int x = v2[i][j];
            if(mp1[x].first - mp2[x].first != k) {
                f = 1;
                // cout << i << " , " << j << endl;
            }
        }
    }
    // cout << "col = " << endl;
    for(int j = 0; j < m; j++) {
        int p = v2[0][j];
        int k = mp1[p].second - mp2[p].second;
        // cout << "p , k = " << p << " " << k  << endl;
        for(int i = 0; i < n; i++) {
            int x = v2[i][j];
            if(mp1[x].second - mp2[x].second != k) {
                f = 1;
                // cout << i << " , " << j << endl;
            }
        }
    }

    // cout << f << endl;
    if(f) cout << "NO" << endl;
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


// 1 2 3
// 4 5 6
// 7 8 9

// 2 1 3
// 5 4 6
// 8 7 9


// 5 4 6
// 2 1 3
// 8 7 9