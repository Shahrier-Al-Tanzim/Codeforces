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
    vector <string> v(2); 
    cin >> v[0] >> v[1];
    v[0].push_back('0');
    v[1].push_back('0');
    int cnt = 0, f = 0;
    string ans = "";
    ans += v[0][0];
    int m = 0;
    for(int i = 0; i < n; i++) {
        if(f) {
            ans += v[f][i];
            // cout << 1 << " ";
            // cout << f << " " << i << endl;
        }
        else {
            if(v[f][i+1] == v[f+1][i]) {
                ans += v[f][i + 1];
                cnt++;
                // cout << "2 ";
                // cout << f << " " << i + 1<< endl;
            }  
            else if(v[f][i+1] == '0' and v[f+1][i] == '1') {
                ans += v[f][i+1];
                // cnt--;
                // cout << "3 ";
                // cout << f << " " << i + 1 << endl;
            } 
            else if(v[f][i+1] == '1' and v[f+1][i] == '0') {
                ans += v[f+1][i];
                f++;
                m = i;
                // cout << "4 ";
                // cout << f << " " << i << endl;
            }
        }

        // ans += v[f][i];
    }
    // nl;
    cout << ans << endl;
    for(int i = 1; i < ans.size() - 1; i++) {
        if(i > m) break;
        if(v[0][i] == v[1][i-1] and v[0][i] == ans[i]) cnt++;
        
        if(v[0][i] != v[1][i-1]) cnt = 0;
    }
    // cout << "m = " << m << endl;
    if(m) cnt++;
    cout << cnt << endl;
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