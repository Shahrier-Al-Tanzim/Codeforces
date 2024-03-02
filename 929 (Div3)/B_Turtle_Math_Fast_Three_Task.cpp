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
    int cnt = 0;
    vector <int> v(n); for(auto &i : v) cin >> i, cnt += i;
    
    int m = cnt % 3, add = 3 - m;
    if(m == 0) cout << 0 << endl;
    else if(m == 2) cout << 1 << endl;
    else {
        vector <int> nd;
        int f = 2;
        for(auto i : v) {
            if(i % 3 == 1) f = 1;
        }

        cout << f << endl;

    }
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

// 2 5 5 = 12
// 3 5 5 = 13
// 4 5 5
// 5 5 5
// 6 5 5
// 7 5 5