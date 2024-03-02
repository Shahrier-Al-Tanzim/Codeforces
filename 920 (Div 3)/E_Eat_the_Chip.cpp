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
    int r, c, xa, ya, xb, yb; cin >> r >> c >> xa >> ya >> xb >> yb;
    if(xa >= xb) {
        cout << "Draw" << endl;
        return;
    } 
    
    int diff = abs (xa - xb);
    if(diff % 2 == 1) {
        int al = max(1ll, ya - (diff/2 + 1ll));
        int ar = min(c  , ya + (diff/2 + 1));
        int bl = max(1ll, yb - (diff/2));
        int br = min(c  , yb + (diff/2));

        if(al <= bl and ar >= br) cout << "Alice" << endl;
        else cout << "Draw" << endl;
    } else {
        int al = max(1ll, ya - (diff/2));
        int ar = min(c  , ya + (diff/2));
        int bl = max(1ll, yb - (diff/2));
        int br = min(c  , yb + (diff/2));

        if(bl <= al and br >= ar) cout << "Bob" << endl;
        else cout << "Draw" << endl;
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


