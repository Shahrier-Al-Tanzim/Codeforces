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
    string s; cin >> s;

    char a[1000][1000];

    int x = sqrt(n);
    if(x * x != n) {cout << "No" << endl; return;}  
    int total = x * 4 - 4; 

    int j = 0;
    a[0][0] = s[0];
    int cnt2 = 0;
    cnt2 = s[0] == '1';
    for(int i = 1; i < n; i++) {
        if(i % x == 0) j++;
        a[j][i % x] = s[i];
        cnt2 += s[i] == '1';
    }  
    j = 0;
    // for(int i = 0; i < x; i++) {
    //     for(int k = 0; k < x; k++) {
    //         cout << a[i][k] << " ";
    //     }
    //     nl;
    // }

    int cnt = 0;
    for(int i = 0; i < x; i++) {
        cnt += a[0][i] == '1';
    }
    for(int i = 0; i < x; i++) {
        cnt += a[x - 1][i] == '1';
    }

    for(int i = 1; i < x - 1; i++) {
        cnt += a[i][0] == '1';
        cnt += a[i][x - 1] == '1';
    }
    

    if(cnt == total and cnt2 == total) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    // cerr << x << endl;
    // cerr << total << " " << cnt << " " << cnt2 << endl;
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
