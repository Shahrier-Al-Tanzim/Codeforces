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
    vector <int> bin;
    int ind = 0;
    for(int i = 32; i >= 0; i--) {
        int p = pow(2, i);
        // cout << p << " ";
        if(p <= n) {
            n -= p;
            bin.push_back(1);

            if(ind == 0) ind = i;
        } else bin.push_back(0);

        // if(n == 0) break;
    }
    nl;
    // vec_print(bin);
    // cout << ind << endl;
    reverse(all(bin));
    int cnt = 0;
    for(int i = 0; i <= ind+1; i++){
        if(bin[i] == 1) {
            cnt++;
            if(cnt == 2) {
                bin[i - 1] =- 1;
            }

            if(cnt >= 2) bin[i] = 0;

        } else {
            if(cnt >= 2) {
                bin[i] = 1;
                cnt = 1;
            } else {
                cnt = 0;
            }
        }
    }   
    for(int i = 32; i >= 0; i--) {
        if(bin[i] != 0) {
            ind = i;
            break;
        }
    }
    cout << ind+1 << endl;
    for(int i = 0; i <= ind; i++) cout << bin[i] << " ";
    // vec_print(bin);       
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

// 256 128 64 32 16 8 4 2 1
//   0  1   1  0  0 0 1 0 0
//   1