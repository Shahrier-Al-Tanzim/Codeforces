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

int v[300008], dp[300003][12];
int n, k; 
// vector <int> v; 

int func(int pos, int rem) {
    if(pos == n) return 0;
    if(dp[pos][rem] != -1) return dp[pos][rem];

    // without doing any operation
    int ret = v[pos] + func(pos + 1, rem);
    for(int i = pos + 1; i < n and i <= pos + rem; i++) {
        int op = i - pos;
        // taking the left most value and replacing all
        ret = min(ret, v[pos] * (op + 1) + func(i+1, rem - op));
        // taking the right most value and replacing all
        ret = min(ret, v[i] * op + func(i, rem7 - op));        
    }
    return dp[pos][rem] = ret;
}

void solve() {
    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= k; j++) dp[i][j] = -1;
    }
    // memset(dp, -1, sizeof dp);
    
    cout << func(0, k) << endl;
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
